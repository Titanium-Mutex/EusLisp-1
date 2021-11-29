;****************************************************************
;;; regular expression
;;; Copyright (c) 2000, Toshihiro Matsui, Electrotechnical Laboratory
;;; calls regcomp and regexec in libc for regular expression matching.
;;;
;;; (regmatch "pattern" "target-string")
;;; pattern, which is a regular expression, is searched for in the
;;; terget-string.  If found, the position (starting index and the ending index)
;;; of the found pattern is returned.
;;; example;
;;; (regmatch "ca[ad]+r" "any string ...") will look for cadr, caar, cadadr ...
;;; in the second argument.
;;; (regmatch ".*=.*" "matsui=penguin")
;;; 
;;; Note: Manuals of Turbolinux 4.x tell different stories about
;;; regexp and regexec.  The following code is based on the
;;; descriptions of 'regexec'.

(let ((mm (load "/lib/libc.so.6")))
(defforeign regcomp mm "regcomp"
	(:string	; preg
	 :string	; regular expression string
	 :integer)	; cflags
	:integer)
(defforeign regexec mm "regexec"
	(:string	; preg (compiled regex pattern about 32byte)
	 :integer	; string for which the pattern is searched
	 :integer	; number of rex-matches returnable
	 :string	; rex-matches (pair of longs)
	 :integer)	; eflag
	:integer)
(defforeign regerror mm "regerror"
	(:integer	; error code
	 :string	; preg (compiled regex pattern)
	 :string	; errbuf
	 :integer)	; size of errbuf
	:integer)
(defforeign regfree mm "regfree" (:string) :integer)
)

(defconstant reg_extended 1)
(defconstant reg_icase    2)
(defconstant reg_newline  4)
(defconstant reg_nosub    8)

;; #define REG_NOTBOL 1
;; #define REG_NOTEOL (1 << 1)

;; returns nil if there is no match
;; 64-bit version
(defun regmatch (pattern target
		 &key (start 0) (extended t) (icase t) (newline t) (nosub nil))
   (let ((preg (make-string 256)) (cflags) (stat)
	 (rex-matches (make-array 128 :element-type :char)) ; 8-byte per a match
 	 (tstart (+ (sys:address target) 16 start)) (result))
     (setq cflags
	   (logior (if extended 1 0)
		   (if icase 2 0)
		   (if newline reg_newline 0)
		   (if nosub reg_nosub 0)))
     (setq stat  (regcomp preg pattern cflags))
     (unless (zerop stat)
	(warn "regmatch: regular expression compilation error ~s" pattern)
	(return-from regmatch nil)) 
     (setq stat 
	(regexec preg tstart 16 rex-matches 0))
     (setq *reg* rex-matches)
     (regfree preg)
     (cond ((zerop stat)
	    (dotimes (i 8)
		(let ((x 0) (y 0) (ii (* i 2)))
		  (dotimes (j 4)
		     (setq x (+ (ash x 8) (aref rex-matches (- (* (1+ ii) 8) j 1))))
		     (setq y (+ (ash y 8) (aref rex-matches (- (* (1+ ii) 8) j 5))))	)
		  (if (>= x #x80000000)
		      (setq x (ash (ash x 32) -32))
		      (setq x (+ start x)) )
		  (if (>= y #x80000000)
		      (setq y (ash (ash y 32) -32))
		      (setq y (+ start y)) )
	          (push (list  y x) result)))
	    (nreverse result) )
	   (t (return-from regmatch nil)))
    )
   )

(provide :regexp)


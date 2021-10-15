;;;; html-readtable.l
;;;; (c) Toshihiro Matsui, AIST, Japan
;;;; May 7, 2003

(defvar *html-readtable* (copy-readtable))

(set-macro-character #\> 'read-rbracket nil *html-readtable*)
;(set-syntax-from-char #\> #\) *html-readtable*)
(set-syntax-from-char #\= #\space *html-readtable*)
;;  #rrggbb notation can fool the Lisp reader.
(set-syntax-from-char #\# #\A *html-readtable*)
(set-macro-character #\{ 'read-brace-form nil *html-readtable*)
(set-syntax-from-char #\} #\rparen *html-readtable*)
(set-syntax-from-char #\; #\space *html-readtable*)
(set-macro-character #\< 'read-bracket-form nil *html-readtable*)

(set-syntax-from-char #\: #\space *html-readtable*)

(set-macro-character #\% nil nil *html-readtable*)
(set-macro-character #\[ nil nil *html-readtable*)

(defun read-brace-form (strm char)
   (prog1 (eval (read strm)) (read strm)))

(defun read-rbracket (strm char)
   (unread-char (read-char strm) strm)
   :right-bracket)

(defun read-bracket-form (strm char)
   (let (x result)
      (while (not (eql (setq x (read strm)) :right-bracket))
	 (push x result))
      (nreverse result)))

(defun read-html (strm &optional (eof-error-p t) (eof-marker nil))
   (let ((*readtable* *html-readtable*))
      (read strm eof-error-p eof-marker)))

;------------------------------------------------------------------
; html reader
;

(defun read-html (strm)
   (let ((eof (cons nil nil))
	 char line result tag
	 in-text-gathering
	 in-body in-table in-p in-tr in-td)
     (while (not (eql (setq char (read-char strm nil eof)) eof))
	(cond ((eql char #\<)	;tag begins?
		(setq tag (read-tag)) 
		(case (car tag)
		   ((table) (read-table))
		   ((tr) (read-table-record))
		   ((td) )))))))




(provide :html-readtable)


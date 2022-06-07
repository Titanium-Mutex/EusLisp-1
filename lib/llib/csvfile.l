;;;; CSV file functions
;;;; May, 2022 Toshihiro Matsui
;;
;;read-cr-lines
;; Each field in a csv file is punctuated (delimited) by CR and LF.
;; Multiple lines in a field is delimited only by an LF.
;; Fields separated by CR-LF in a csv file are represented by strings and are
;; collected in a list.
;; A csv file composed of N records is read as a list of N pieces fo strings.

(defun read-cr-lines (fn)
   (setq fn (namestring (merge-pathnames fn "/home/matsui/syllabus.utf8/")))
   (let* ((z (file-size fn))
	  (buffer (read-buffer fn (make-string z)))
	  (lines) (buf) (i 0) (ch) (lf) (eof nil))
       (labels ((nextch ()
			(if eof (error "beyond eof"))
			(setq ch (aref buffer i))
			(incf i)
			(setq eof  (>= i z))
			ch )	)
	  (nextch)
	  (while (not eof)
	     (setq buf nil)	
	     (while (not (= ch #x0d)) (push ch buf) (nextch))
	     (push (coerce (nreverse buf) string) lines) 
	     (setq lf (nextch))
	     (if (/= lf #x0a) (format *error-output* "Newline is expected, but #x~2x hit.~%" lf))
	     (if (not eof) (nextch))
	     )
	  (nreverse lines))))


; split-csv-line
;; Each line (record) in a csv file is separated into a list of strings, each string
;; representing one field.

(defun split-csv-line (line)
   (let ((field nil) (fields nil)
	 (index 0) (len (length line))
	 (ch))
      (while (< index len)
	 (setq ch (aref line index))
	 (incf index)
	 (if (= ch #\,)
	     (progn (push (coerce (nreverse field) string) fields)
		    (setq field nil))
	     (push ch field))
	 (if (= index len)	;at the tail of a record
	     (push (coerce (nreverse field) string) fields) )
	 )
	(nreverse fields)))
	 


;; Many lines of csv records are parsed looking for the designated pattern (just a string).
;; If the pattern is found, corresponding field is extracted referring the dest description.
;; If dest is 0, the rest of the string in the field where the pattern was found is taken.
;; If dest is 1 .. n, usually 1, the field next to the pattern field is taken.
;; if dest is (n m), where n and m are integers, usually only one, the mth field in the nth
;; next record is taken. IF dest is (1 1), the second field of the next line is taken.
;; If dest is (1 1 n), multiple fields from the next record to nth record, terminated by
;; a null field are taken.

(defun extract-field (lines pattern dest &optional width) 
   (let ((fields) (field) (result) (match nil) (n) (line) (lindex 0) (findex))
      (while lines
	 (setq fields (split-csv-line (pop lines)))
	 (while fields
	    (setq field (pop fields))
	    (setq match (string-match pattern field))
	    (when match
	       (cond 
		 ((eql dest 0)
		  (return-from extract-field
			(subseq field (+ match (length pattern)))))
		 ((numberp dest)
		  (return-from extract-field
		     (nth (1- dest) fields)))
		 ((consp dest)
		  ;; (print lines)
		  (cond ((null (cddr dest))
			  (return-from extract-field
				(nth (cadr dest)
					(split-csv-line (nth (1- (car dest)) lines)) )))
			(t (while (> (length (setq field
						(nth (cadr dest)
						     (split-csv-line (nth (1- (car dest)) lines)) )) )
				     0)
				(push field result)
				(pop lines))
			    (return-from extract-field (nreverse result))) ))
		 )) ;cond when
	    ) ;while fields
	) ;while lines
   ) )

;; define a csv field pattern
;; to find a specific field in a csv file.
;; May, 2022
;; The idea is that an excel file is often consisted of a header and values,
;; i.e., key-value pair. We want to extract the value designated by the key.
;; The key-value pair may in the same field (dest=0),
;; Or in the next field (dest=1).  If the value is in the third field after
;; the key, dest=3;
;; If the value is in the next line, dest should be a list designating the
;; number of lines after the key, and the position of the field in the record
;; from the beginning of the record. 

;; def-csv-pattern name key dest)
;; name: the pattern name; the name symbol's plist holds
;; the pattern
;; key: a trigger word starting the pattern
;; dest: 0- get the target in the pattern field
;;       1.. get the target in the next field in the same record
;;       (1 1) in the second field of the next line
;;	 (1 2 n) collect the third fields of the next record, and the next
;;		until a null field appears --this should be ((1 n) 2)
;;

(defmacro def-csv-pattern (name key dest)
   `(progn (putprop ',name ',key :csv-pattern )
           (putprop ',name ',dest :csv-field )
           ',name)
   )


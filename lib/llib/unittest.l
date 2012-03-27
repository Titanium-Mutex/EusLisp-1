;;;
;;; based on euslib/jsk/unittest.l by R.Ueda
;;;

(defvar *unit-test* nil)

(defun escape-xml-string (str1)
  (let* ((str2 (make-string (+ (length str1)
			       (* (count #\< str1) 3)
			       (* (count #\> str1) 3)
			       (* (count #\& str1) 4)))))
    (do ((i1 0 (1+ i1))
	 (i2 0 (1+ i2)))
	((>= i1 (length str1)))
      (cond ((eq (elt str1 i1) #\<)
	     (setf (elt str2 i2) #\&) (incf i2)
	     (setf (elt str2 i2) #\l) (incf i2)
	     (setf (elt str2 i2) #\t) (incf i2)
	     (setf (elt str2 i2) #\;))
	    ((eq (elt str1 i1) #\>)
	     (setf (elt str2 i2) #\&) (incf i2)
	     (setf (elt str2 i2) #\g) (incf i2)
	     (setf (elt str2 i2) #\t) (incf i2)
	     (setf (elt str2 i2) #\;))
	    ((eq (elt str1 i1) #\&)
	     (setf (elt str2 i2) #\&) (incf i2)
	     (setf (elt str2 i2) #\a) (incf i2)
	     (setf (elt str2 i2) #\m) (incf i2)
	     (setf (elt str2 i2) #\p) (incf i2)
	     (setf (elt str2 i2) #\;))
	    (t
	     (setf (elt str2 i2) (elt str1 i1))))
      )
    str2))

(defun unittest-error (code msg1 form &optional (msg2))
  (format *error-output* "~C[1;3~Cm~A unittest-error: ~A"
	  #x1b (+ 1 48)   *program-name* msg1)
  (if msg2 (format *error-output* " ~A" msg2))
  (if form (format *error-output* " in ~s" form))
  (format *error-output* ", exitting...~C[0m~%"  #x1b)
  (send *unit-test* :increment-failure form msg1 code)
  (send *unit-test* :print-result)
  (exit 1))

(defun unittest-sigint-handler (sig code)
  (format *error-output* "unittest-sigint-handler ~A~%" sig)
  (send *unit-test* :increment-failure "" (format nil "signal-handler ~A" sig) code)
  (send *unit-test* :print-result)
  (exit 1))

(defclass unit-test-result
  :super propertied-object
  :slots (name tests failures time))
(defmethod unit-test-result
  (:init (n) (setq name n tests nil failures nil time 0))
  (:tests () tests)
  (:num-tests () (length tests))
  (:num-failures () (if failures 1 0)) ;; need fix
  (:num-successes () (- (send self :num-tests) (send self :num-failures)))
  (:time () time)
  (:prin1
   (strm)
   (format strm "RESULT: ~A~%" name)
   (format strm "  TEST-NUM: ~A~%" (send self :num-tests))
   (format strm "    PASSED:   ~A~%" (send self :num-successes))
   (format strm "    FAILURE:  ~A~%" (send self :num-failures))
   )
  (:prin1-xml
   (strm)
   (format strm "  <testcase name=\"~s\" status=~s time=\"~d\" classname=\"~s\">~%" name "run" time name)
   (dolist (ret failures)
     (let ((test (elt ret 0))
	   (msg  (elt ret 1))
	   (trace (elt ret 2)))
       (when trace
	 (format strm "   <failure message=~s type=\"AssertionError\">~%" (escape-xml-string msg))
	 (format strm "Test:~A~%" (escape-xml-string (prin1-to-string test)))
	 (format strm "Trace:~A~%" (escape-xml-string (prin1-to-string trace)))
	 (format strm "Message:~A~%" (escape-xml-string (prin1-to-string msg)))
	 (format strm "   </failure>~%"))))
   (format strm "  </testcase>~%")
   )
  )

(defclass unit-test-container
  :super propertied-object
  :slots (result functions log-fname output-mode))

(defmethod unit-test-container
  (:init
   (&key ((:log-fname fname)))
   (setq result nil)
   (setq functions nil)
   (setq log-fname fname)
   (when log-fname
     (warning-message 3 "output to ~A~%" log-fname)
     (setq output-mode :xml))
   self)
  (:functions () (reverse functions))
  ;;
  (:add-function (name) (push name functions))
  (:increment-test
   (test)
   (if result (push test (unit-test-result-tests (car result)))))
  (:increment-failure
   (test msg trace)
   (if result (push (list test msg trace) (unit-test-result-failures (car result))))
   (when trace
     (format *error-output* "~C[3~Cm[ERROR] test ~A failed" #x1b 49 test)
     (format *error-output* " ... (~A ~A)" msg trace)
     (format *error-output* ".~C[0m~%" #x1b)))
  (:set-time-to-current-result
   (time) ;; msec
   (if result (setf (unit-test-result-time (car result)) (round time))))
  (:init-result
   (func-sym)
   (push (instance unit-test-result :init func-sym) result))
  (:clear-result ()
   (setq result nil)
   (send self :init-result 'all-test)
   (send self :increment-test 'all-test))
  ;;
  (:print-xml-result
   (&optional (strm t))
   (let ((all-tests (apply #'+ (send-all result :num-tests)))
         (all-failures (apply #'+ (send-all result :num-failures)))
         (all-times (apply #'+ (send-all result :time))))
     (format strm "<testsuite tests=\"~d\" failures=\"~d\" disabled=\"~d\" errors=\"~d\" time=\"~d\" name=\"AllTests\">~%" all-tests all-failures 0 0 all-times)
     (dolist (r (reverse result)) (send r :prin1-xml strm))
     (format strm "</testsuite>~%")
     ))
  (:print-normal-result
   (&optional (strm t))
   (let ((all-tests (apply #'+ (send-all result :num-tests)))
         (all-successes (apply #'+ (send-all result :num-successes)))
         (all-failures (apply #'+ (send-all result :num-failures))))
     (format strm "ALL RESULTS:~%")
     (format strm "  TEST-NUM: ~A~%" all-tests)
     (format strm "    PASSED:   ~A~%" all-successes)
     (if (> all-failures 0)
         (format strm "~C[3~Cm" #x1b 49))
     (format strm "    FAILURE:  ~A~%" all-failures)
     (if (> all-failures 0)
         (format strm "~C[0m" #x1b))
     (dolist (r (reverse result)) (prin1 r strm))
     ))
  (:print-result
   ()
   (send self :print-normal-result)
   (when (and result (eq output-mode :xml))
     (let ((strm (open log-fname :direction :output
		       :if-exists :append
		       :if-does-not-exist :create)))
       (send self :print-xml-result strm)
       (close strm))))
  )

(defmacro deftest (name &rest body)
  `(progn
     ;; its not cool...
     (defun ,name ()
       ,@body)
     (send *unit-test* :add-function ',name)
     ',name))

(defmacro assert (pred &optional (message "") &rest args)
  (with-gensyms
   (ret)
   `(let* (failure (ret ,pred))
      (warning-message 2 "testing [~A] ~A~%" (format nil ,message ,@args) ',pred)
      ;; lisp::step could not work with macros..
      ;;     (if (and (listp ',pred) (functionp (car ',pred)))
      ;;	 (setq ret (lisp::step ,pred))
      ;;       (setq ret ,pred))
      ;;
      (if (not ret)
	  ;; escape <> for xml
	  (send *unit-test* :increment-failure ',pred (format nil ,message ,@args)
		(escape-xml-string (subseq (send *error-output* :buffer) 0 (or (position 0 (send *error-output* :buffer)) (length (send *error-output* :buffer)))))))
      )))

(defun run-test (func-sym)
  (let ((func (symbol-function func-sym)) tm)
    ;; initilize result
    (send *unit-test* :init-result func-sym)
    (format t "TEST-NAME: ~A~%" func-sym)
    (format t "  now testing...~%")
    (send *unit-test* :increment-test func-sym)
    (setq tm (instance mtimer :init))
    (send tm :start)
    (funcall func)
    (send *unit-test* :set-time-to-current-result (send tm :stop))))

(defun run-all-tests ()
  ;; initalize *unit-test-result*
  (send *unit-test* :clear-result)
  (dolist (u (send *unit-test* :functions))
    (run-test u))
  (send *unit-test* :print-result)
  t)

(defun init-unit-test (&key log-fname)
  (let* ((p "--gtest_output=xml:")
         (s (find-if #'(lambda (x) (substringp p x)) lisp::*eustop-argument*))
         (xml-fname (if s (string-left-trim p s))))
    (if xml-fname (setq log-fname xml-fname))

    (setq lisp::*exit-on-fatal-error* t)
    (lisp::install-error-handler 'unittest-error)
    (unix:signal unix::sigint 'unittest-sigint-handler)
    (unix:signal unix::sighup 'unittest-sigint-handler)

    (setq *unit-test* (instance unit-test-container :init :log-fname log-fname))
    t))

(provide :unittest)
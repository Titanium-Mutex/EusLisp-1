;; Topological sort in directed acyclic graph (dag)
;; 2018-11-21 (c) Toshihiro Matsui, IISEC
;;

;(setq *print-circle* t)

(defparameter *dagset* nil)
(defparameter *revdag* nil)

(defun define-node (nlist)
   (setq *dagset* (nconc *dagset* (list nlist)))
   (let ((revlist))
       (dolist (n (cdr nlist))  ;;for each referenced node
         (setq revlist (assoc n *revdag*))
	 (if revlist
	     (nconc revlist (list (car nlist))) ;already defined, add ref
	     (setq *revdag* (nconc *revdag* 	;first reference
					(list (list n (car nlist))))) )
	)) ;let
   *dagset*)


(defun super-assoc (x alist)
   (if (atom alist)
	nil
	(if (eq x (car alist))
	    (list alist)
	    (append  (super-assoc x (car alist))
		    (super-assoc x (cdr alist))))))


(defun unpointed-nodes (&optional (dag *dagset*))
    (let ((dests (mapcan #'(lambda (x) (copy-seq (cdr x))) dag)))
       (mapcan #'(lambda (y) (unless (member y dests) (list y)))
	   (mapcar #'car dag))) )

(defun tsort (&optional (dag (copy-tree *dagset*)))
   (let ((nexts (unpointed-nodes dag))  node
	 sorts)	;sorted result
	(while nexts        
	   (setq node (pop nexts))
	   (push node sorts)
	   (setq dag (delete (assoc node dag) dag))
	   (setq nexts (union nexts (unpointed-nodes dag)) )  )
	(reverse sorts)))

(defparameter *computed-sorts* nil)
(defparameter *count* 0)
(defun sort-syms (symlist) ;sort destroys the arg list
   (sort symlist #'string<= #'symbol-name))

(defun tsort-all (&optional (dag (copy-tree *dagset*)) (removed-nodes))
   (incf *count*)
   (cond ((null dag) nil)
	 ((null (cdr dag)) (list (list (caar dag))))
	 ((assoc removed-nodes *computed-sorts* :test #'equal)
;	(format t "assoc hit, ~s~%" (assoc removed-nodes *computed-sorts*
;					 :test #'equal))
	  (cdr (assoc removed-nodes *computed-sorts* :test #'equal)))
	 (t
	   (let (node-next dag2	 new-removes sorts new-sorts)
	      (dolist (src (unpointed-nodes dag))
		   (setq node-next (assoc src dag))
		   (setq dag2 dag)
		   (setq dag (delete node-next dag))
		   (setq new-removes (sort-syms (cons src 
			       (copy-seq removed-nodes))))
		   (setq new-sorts
			(mapcar #'(lambda (x) (cons src x)) 
				(tsort-all dag new-removes))) 
		   (setq sorts (nconc sorts new-sorts))
		   ;;(format t "removed: ~s  newsorts: ~s~%" new-removes new-sorts)
		   ; recover dag and revdag
		   (if (not (eq (car dag2) node-next))
			(setq dag (nconc dag (list node-next)))
			(setq dag dag2) )
		  ) ;dolist
	; memory it
        (push (cons removed-nodes sorts) *computed-sorts*)
	(reverse sorts)))
   ))



;;
;; create initial graphs
;;

(defun simple-dag ()
    (setq *dagset* nil *revdag* nil)
    (define-node '(a b c))
    (define-node '(b d))
    (define-node '(c d))
    (define-node '(d)))

(defun simple-dag2 ()
    (setq *dagset* nil *revdag* nil)
    (define-node '(b d))
    (define-node '(c d))
    (define-node '(d)))

(defun test-dag ()
	(setq *dagset* nil  *revdag* nil)
	(define-node '(a c d))
	(define-node '(b d e))
	(define-node '(h))
	(define-node '(f h))
	(define-node '(g h))
	(define-node '(c f))
	(define-node '(d f))
	(define-node '(e g))
	)

(defun hockey-gears ()
	(setq *dagset* nil  *revdag* nil)
	(define-node '(undershorts compression-shorts))
	(define-node '(socks hose))
	(define-node '(compression-shorts hose cup))
	(define-node '(hose pants))
	(define-node '(cup pants))
	(define-node '(pants skates sweater))
	(define-node '(skates leg-pads))
	(define-node '(t-shirt chest-pad))
	(define-node '(chest-pad sweater))
	(define-node '(sweater mask))
	(define-node '(mask catch-glove))
	(define-node '(leg-pads catch-glove))
	(define-node '(catch-glove blocker))
	)

(defun gongbao-jiding ()
   (setq *dagset* nil  *revdag* nil)
   (define-node '(prepare-marinade dip-chicken-in-marinade))
   (define-node '(cut-chicken dip-chicken-in-marinade))
   (define-node '(dip-chicken-in-marinade heat-chicken))
   (define-node '(heat-chicken add-garlic-and-ginger))
   (define-node '(cut-garlic add-garlic-and-ginger))
   (define-node '(cut-ginger add-garlic-and-ginger))
   (define-node '(add-garlic-and-ginger finish-chicken))
   (define-node '(finish-chicken remove-chicken))
   (define-node '(cut-carrot heat-carrot-celery-peanut))
   (define-node '(cut-celery heat-carrot-celery-peanut))
   (define-node '(wash-peanut heat-carrot-celery-peanut))
   (define-node '(remove-chicken heat-carrot-celery-peanut))
   (define-node '(heat-carrot-celery-peanut put-back-chicken))
   (define-node '(put-back-chicken add-cooking-sauce))
   (define-node '(prepare-cooking-sauce add-cooking-sauce))
   (define-node '(add-cooking-sauce heat-until-darken))
   (define-node '(heat-until-darken remove-from-heat))
   )


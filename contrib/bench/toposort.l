;; Topological sort in directed acyclic graph (dag)
;; 2018-11-21 (c) Toshihiro Matsui, IISEC
;;

(setq *print-circle* t)

(defparameter *dagset* nil)

(defun define-node (x)
   (let (nodes n top)
      (dolist (y (cdr x))
	 (push (if (assoc y *dagset*) 
		   (assoc y *dagset*)
		   (car (push (list y) top)))
	       nodes))
      (if (assoc (car x) *dagset*)
	  (rplacd (assoc (car x) *dagset*) nodes)
	  (push (cons (car x) nodes) *dagset*)) 
      (nconc *dagset* top)
      *dagset*))

(define-node '(a c d))
(define-node '(b d e))
(define-node '(h))
(define-node '(f h))
(define-node '(g h))
(define-node '(c f))
(define-node '(d f))
(define-node '(e g))


(defun super-assoc (x alist)
   (if (atom alist)
	nil
	(if (eq x (car alist))
	    (list alist)
	    (append  (super-assoc x (car alist))
		    (super-assoc x (cdr alist))))))


(defun tsort (dagset)
   (let (linear-seq candidates)
      (while dagset
	 (setq candidates nil)
	 (dolist (x dagset)
	   (when (null (cdr (super-assoc (car x) dagset)))
	     ;; (caar dagset) is a lonely node, i.e., no pointer to this
	     (format t "pick up ~s~%" (car x))
	     (push x candidates)) )
	 (push (mapcar #'car candidates) linear-seq)
	 (dolist (x candidates)
	    (setq dagset (delete x dagset))
	     )	)
      (nreverse linear-seq))
   )
	    

(defun hockey-gears ()
	(setq *dagset* nil)
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
   (setq *dagset* nil)
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


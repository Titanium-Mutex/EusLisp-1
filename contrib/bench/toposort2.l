3;; topological sort version 2
;; (c) Toshihiro Matsui, IISEC, 2018

;; *dagset*    list of source --> multiple destinations
;; *rev-dag*   list of dest from multiple sources
;;
(defparameter *dagset* nil)
(defparameter *rev-dag* nil)

(defun define-node2 (nlist)
   (push nlist *dagset*)
   (let ((revlist))
      (dolist (n (cdr nlist))
         (setq revlist (assoc n *rev-dag*))
	 (if revlist
	     (nconc revlist (list (car nlist)))
	     (setq *rev-dag* (nconc *rev-dag* 
					(list (list n (car nlist))))) )
	))
    (list *dagset* *rev-dag*))


(defun tsort (&optional (dag (copy-tree *dagset*))
			(revdag (copy-tree *rev-dag*)))
   (let* ((sources (mapcar #'car dag))
	  (dests (mapcar #'car revdag))
	  (nexts (mapcan #'(lambda (s) (if (not (member s dests)) (list s)))
			 sources))
	  node connects
	  sorts)	;sorted result
	(while nexts        
	   (setq node (pop nexts))
	   (push node sorts)
	   (dolist (con (cdr (assoc node dag))) 
	      (delete node (assoc con revdag))
	      (if (null (cdr (assoc con revdag)))
		  (push con nexts))) )
	(reverse sorts)))

;; tsort-all finds order of groups
(defun tsort-all (&optional (dag (copy-tree *dagset*))
			    (revdag (copy-tree *rev-dag*)))
   (let* ((sources (mapcar #'car dag))
	  (dests (mapcar #'car revdag))
	  (nexts (mapcan #'(lambda (s) (if (not (member s dests)) (list s)))
			 sources))
	  sorts)	;sorted result
	(while nexts        
	   (let (next-nexts next-connects)
	      (format t "nexts=~s~%" nexts)
	      (push nexts sorts)
	      (setq next-connects
		 (remove-duplicates
		   (mapcan #'(lambda (x)
		      (copy-seq (cdr (assoc x dag))) ) nexts) ))
	      (format t "next-connects=~s~%" next-connects)
	      ;; (break "@")
              (dolist (con next-connects)	;delete each nexts
	         (dolist (node nexts)
	            (delete node (assoc con revdag)) 
		    (if (null (cdr (assoc con revdag)))
		        (push con next-nexts))) )
	      ;; (setq next-nexts (remove-duplicates next-nexts))
	      (setq nexts next-nexts)) )
	(reverse sorts)))


;;
;; create initial graphs
;;
(defun simple-dag ()
    (setq *dagset* nil *rev-dag* nil)
    (define-node2 '(a b c))
    (define-node2 '(b d))
    (define-node2 '(c d)))


(defun test-dag ()
	(setq *dagset* nil  *in-degree* nil *rev-dag* nil)
	(define-node2 '(a c d))
	(define-node2 '(b d e))
	(define-node2 '(h))
	(define-node2 '(f h))
	(define-node2 '(g h))
	(define-node2 '(c f))
	(define-node2 '(d f))
	(define-node2 '(e g))
	*dagset*
	)

(defun hockey-gears ()
	(setq *dagset* nil  *in-degree* nil *rev-dag* nil)
	(define-node2 '(undershorts compression-shorts))
	(define-node2 '(socks hose))
	(define-node2 '(compression-shorts hose cup))
	(define-node2 '(hose pants))
	(define-node2 '(cup pants))
	(define-node2 '(pants skates sweater))
	(define-node2 '(skates leg-pads))
	(define-node2 '(t-shirt chest-pad))
	(define-node2 '(chest-pad sweater))
	(define-node2 '(sweater mask))
	(define-node2 '(mask catch-glove))
	(define-node2 '(leg-pads catch-glove))
	(define-node2 '(catch-glove blocker))
	)

(defun gongbao-jiding ()
   (setq *dagset* nil  *in-degree* nil *rev-dag* nil)
   (define-node2 '(prepare-marinade dip-chicken-in-marinade))
   (define-node2 '(cut-chicken dip-chicken-in-marinade))
   (define-node2 '(dip-chicken-in-marinade heat-chicken))
   (define-node2 '(heat-chicken add-garlic-and-ginger))
   (define-node2 '(cut-garlic add-garlic-and-ginger))
   (define-node2 '(cut-ginger add-garlic-and-ginger))
   (define-node2 '(add-garlic-and-ginger finish-chicken))
   (define-node2 '(finish-chicken remove-chicken))
   (define-node2 '(cut-carrot heat-carrot-celery-peanut))
   (define-node2 '(cut-celery heat-carrot-celery-peanut))
   (define-node2 '(wash-peanut heat-carrot-celery-peanut))
   (define-node2 '(remove-chicken heat-carrot-celery-peanut))
   (define-node2 '(heat-carrot-celery-peanut put-back-chicken))
   (define-node2 '(put-back-chicken add-cooking-sauce))
   (define-node2 '(prepare-cooking-sauce add-cooking-sauce))
   (define-node2 '(add-cooking-sauce heat-until-darken))
   (define-node2 '(heat-until-darken remove-from-heat))
   )



      

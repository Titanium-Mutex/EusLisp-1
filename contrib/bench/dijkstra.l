;;;; dijkstra.l
;;;; Dijkstra algorithm to find the shortest path in a graph
;;;  (c) Toshihiro Matsui, 2018
;;;

;; a graph node
;;  (node-name shortest-cost prev-node-name in-degree
;;		(next1 cost1) (next2 cost2) ...)

(defparameter *graph* nil)

(defun defnode (name destination cost)
   (let (desc dest) ;node description
      (cond ((setq desc (assoc name *graph*))
	     (if (setq dest (assoc destination (cddddr desc)))
		 (rplaca (cdr dest) cost)
		 (nconc desc (list (setq dest (list destination cost))))) )
	    (t  ; name appears first
		(setq *graph* 
		      (nconc *graph*
			     (list (setq dest
					(list name
					      65536	;big value
					      nil	;pred-node
					      0		;in-degree
					      (list destination cost))))) ))
	    )
      (unless (assoc destination *graph*)
	 (setq *graph* (nconc *graph* (list (list destination 65536 nil 0)))))
      (incf (cadddr (assoc destination *graph*))) ;;inc in-degree
      dest))


(defun start-nodes (&optional (g *graph*))
   (let ((node-names (mapcar #'car g))
	 (nexts (remove-duplicates
		   (mapcan #'(lambda (x)
		       (mapcan #'(lambda (y) (list (car y)))
			       (cddddr x)))
		       g))) )
	(set-difference node-names  nexts)) )

(defun end-nodes  (&optional (g *graph*))
   (mapcan #'(lambda (x) (unless (cddddr x) (list (car x)))) g) )

(defun set-start-shortest (&optional (g *graph*))
    (mapcar #'(lambda (x) (rplaca (cdr (assoc x g)) 0)) (start-nodes g)) )

;; defstarts cannot be called twice.
(defun defstart-end (&optional (startsym 'start) (endsym 'end) (g *graph*))
    (dolist (s (start-nodes g))
       (defnode startsym s 0))
    (dolist (e (end-nodes g))
       (defnode e endsym 0) )
    )

(defun next-nodes (u &optional (g *graph*))
    (mapcar #'car (cddddr (assoc u g))))

(defun all-node-names (&optional (g *graph*))
    (mapcar #'car g))

(defun set-indegree (&optional (g *graph*))
   ; reset in-degree to zero
   (dolist (n g) (setf (cadddr n) 0))
   ; increment in-degree according to references to it
   (dolist (n g)
	(dolist (next (cddddr n))
	   (incf (cadddr (assoc (car next) g))) ) ) )

(defun toposort (&optional (g *graph*))
   (set-indegree g)
   (let ((nexts (mapcan #'(lambda (x) (if (= (cadddr x) 0) (list (car x))))
			g)) 
	 (u) (sorts))
	(while nexts
	   (setq u (pop nexts))
	   (push u sorts)
	   (dolist (v (next-nodes u))
	      (if (= 0 (decf (cadddr (assoc v g))))
		  (push v nexts))))
	(nreverse sorts )))

(defun relax (u v)
   (let* ((u-desc (assoc u *graph*))
	  (v-desc (assoc v *graph*))
	  (weight (second (assoc v u-desc))) )
	(if (null weight)	; no path from u to v
	    (return-from relax nil))
	(when (< (+ (second u-desc) weight) (second v-desc))
	    (setf (second v-desc) (+ (second u-desc) weight)) 
	    (setf (third v-desc) u))))

(defun shortest (&optional (startsym 'start) (endsym 'end) (g *graph*))
   (set-start-shortest g)
   (dolist (u (toposort g))
      (dolist (v (next-nodes u))  (relax u v) ) )
	;
   (let ((prev endsym)  ;traverse from the endsym
	 (path))
      (while prev
	 (push prev path)
	 (setq prev (caddr (assoc prev g))))
      path)
   )

(defun find-shortest (nodes)
   (let ((node) (ss) (dist))
      (setq ss (pop nodes) dist (cadr ss))
      (while nodes
	 (setq node (pop nodes))
	 (when (< (cadr node) dist)
	     (setq ss node dist (cadr node)))
	 )
      ss))

(defun dijkstra (&optional (startsym 'start) (endsym 'end) (g *graph*))
   (let ((q (copy-list g))   (u))
      (set-start-shortest q)
      (while q
	 (setq u (find-shortest q))
	 ; (print u)
	 (setq q (remove u q))
         (dolist (v (next-nodes (car u))) 
		; (print (list (car u) v))
	        (relax (car u) v) ) )
	;
   (let ((prev endsym)  ;traverse from the endsym
	 (path))
      (while prev
	 (push prev path)
	 (setq prev (caddr (assoc prev g))) )
      path)
   )


(progn
	(setq *graph* nil)
	(defnode 'a 'c 3)
	(defnode 'a 'd 4)
	(defnode 'b 'd 2)
	(defnode 'c 'e 2)
	(defnode 'c 'f 6)
	(defnode 'd 'h 5)
	(defnode 'e 'f 3)
	(defnode 'e 'g 1)
	(defnode 'e 'd 2)
	(defnode 'e 'g 4)
	(defnode 'd 'g 3)
	; all nodes added
	(defstart-end 'start 'end *graph*)
 )



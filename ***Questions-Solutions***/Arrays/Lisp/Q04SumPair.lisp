(defparameter *array* '(8 7 2 5 3 1))
(defparameter *sum* 10)
(setq *array* (sort *array* '<))
(defparameter *startIndex* 0)
(defparameter *endIndex* (- (length *array*) 1))
(loop while (< *startIndex* *endIndex*) do
     (if (= (+ (nth *startIndex* *array*) (nth *endIndex* *array*)) *sum*)
	 (progn (format t "(~d ~d)~%" (nth *startIndex* *array*) (nth *endIndex* *array*))
		(setf *startIndex* (+ *startIndex* 1))
		(setf *endIndex* (- *endIndex* 1))))
     (if (> (+ (nth *startIndex* *array*) (nth *endIndex* *array*)) *sum*)
	 (setf *endIndex* (- *endIndex* 1)))
     (if (< (+ (nth *startIndex* *array*) (nth *endIndex* *array*)) *sum*)
	 (setf *startIndex* (+ *startIndex* 1))))
     
(write *array*)

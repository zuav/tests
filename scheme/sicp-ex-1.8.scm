;;; Exercise 1.8
;;; 
;;; Newton's method for cube roots


(define (cube-root x)
  (cube-root-iter 1 x))

(define (cube-root-iter guess x)
  (if (good-enough? guess x)
      guess
      (cube-root-iter (improve guess x) x)))


;;
;; x/y^2 + 2y
;; ----------
;;     3
;;
(define (improve guess x)
  (/ (+ (/ x (square guess)) (* 2.0 guess))
     3.0))

(define (good-enough? guess x)
  (< (abs (- (cube guess) x)) 0.001))


(define (square x)
  (* x x))

(define (cube x)
  (* x x x))

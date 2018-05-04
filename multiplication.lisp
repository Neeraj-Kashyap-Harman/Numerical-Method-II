;; Print Multiplication Tables
;;
;; This demonstrates CL's format function and it's ability
;; to print out Roman Numerals, Numbers in Words etc.. 
;;
;; Unlikely to be ever used!

(defun multiplication-table (number)
  (loop for i from 1 below 12
       do (format t "~10<~@r~;times~> ~:d = ~r~%" i number (* i number))
       collect i into list-of-i
       collect (* i number) into list-of-j
       finally (return (values list-of-i list-of-j))))

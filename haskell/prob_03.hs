--
-- Problem 3: Find the kth element of a list
--
-- Example:
-- *Main> myElementAt [1, 3, 5, 6, 7] 3
-- 5 
--
myElementAt :: [x] -> Int -> x
myElementAt _ 0 = error "Not a valid index"
myElementAt (x : _) 1 = x
myElementAt (_ : xs) n = myElementAt xs (n - 1)

myElementAt' x n = x !! (n - 1)

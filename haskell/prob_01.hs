--
-- Problem 1: Find the last element of a list
--
-- Example:
-- *Main> myLast [1, 2, 3, 4]
-- 4
--
myLast :: [x] -> x
myLast [] = error "Empty list"
myLast [x] = x
myLast (_ : xs) = myLast xs

myLast' = last

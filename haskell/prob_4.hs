--
-- Problem 4: Find the number of elements of a list
--
-- Example:
-- *Main> myLength "This is a string"
-- 16
--
myLength :: [x] -> Int
myLength [] = 0
myLength (_ : xs) = 1 + myLength xs

myLength' = length

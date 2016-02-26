--
-- Problem 5: Reverse a list
--
-- Example:
-- *Main> myReverse [1, 2, 3, 4]
-- [4,3,2,1]
--
myReverse :: [x] -> [x]
myReverse [] = []
myReverse (x : xs) = myReverse xs ++ [x] 

myReverse' = reverse

--
-- Problem 14: Duplicate the elements of a list
--
-- Example:
-- *Main> duplicate [1, 2, 3]
-- [1, 1, 2, 2, 3, 3]
--
duplicate :: [x] -> [x]
duplicate [] = []
duplicate (x:xs) = [x, x] ++ (duplicate xs)

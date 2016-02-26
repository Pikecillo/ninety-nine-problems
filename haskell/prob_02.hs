--
-- Problem 2: Find the last but one element of a list
--
-- Example:
-- *Main> myButLast [1, 2, 3, 4]
-- 3
--
myButLast :: [x] -> x
myButLast [] = error "Empty list"
myButLast [_] = error "List has only one element"
myButLast [x, _] = x
myButLast (_ : xs) = myButLast xs

myButLast' = last.init

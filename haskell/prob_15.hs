--
-- Problem 15: Replicate the elements of a list a number of times
--
-- Example:
-- *Main> repli "abc" 3
-- "aaabbbccc"
--
repli :: [x] -> Int -> [x]
repli _ 0 = []
repli [] n = []
repli (x:xs) n = take n (repeat x) ++ repli xs n

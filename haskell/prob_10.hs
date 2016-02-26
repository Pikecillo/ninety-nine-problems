--
-- Problem 10: Run-length encoding of a list. Consecutive duplicates of
-- elements are encoded as lists (N E) where N is the number of duplicates
-- of the element E.
--
-- Example:
-- *Main> encode [1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 4, 4]
-- [(3,1),(2,2),(5,3),(2,4)]
--
auxEncode :: (Eq x) => [[x]] -> [(Int, x)]
auxEncode [] = []
auxEncode (x:xs) = (length x, head x):(auxEncode xs)

encode :: (Eq x) => [x] -> [(Int, x)]
encode x = auxEncode (pack x)

--
-- Problem 8: Eliminate consecutive duplicates of list elements
--
-- Example:
-- *Main> compress "aaaabbbcccdddee"
-- "abcde"
--
compress :: (Eq x) => [x] -> [x]
compress [] = []
compress [x] = [x]
compress (x:xs) =
  if head xs == x then
    compress xs
  else
    x:(compress xs) 

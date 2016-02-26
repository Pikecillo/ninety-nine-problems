--
-- Problem 11: Modify the result of problem 10 in such a way that if an
-- element has no duplicates it is simply copied into the result list.
-- Only elements with duplicates are transferred as (N E) lists.
--
-- Example:
-- *Main> encodeModified "aaaabccaadeeee"
-- [Multiple 4 'a',Single 'b',Multiple 2 'c',
-- Multiple 2 'a',Single 'd',Multiple 4 'e']
--
data Element x = Single x | Multiple Int x deriving Show
auxEncodeModified :: (Eq x) => [[x]] -> [Element x]
auxEncodeModified [] = []
auxEncodeModified (x:xs) =
  if length x == 1 then
     Single(head x) : (auxEncodeModified xs)
  else
     Multiple (length x) (head x) : (auxEncodeModified xs)

encodeModified :: (Eq x) => [x] -> [Element x]
encodeModified x = auxEncodeModified (pack x)

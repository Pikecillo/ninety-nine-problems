--
-- Problem 6: Find out whether a list is a palindrome
--
-- Example:
-- *Main> isPalindrome [1, 2, 3, 4]
-- False
-- *Main> isPalindrome "anana"
-- True
isPalindrome :: (Eq x) => [x] -> Bool
isPalindrome [] = True
isPalindrome [x] = True
isPalindrome (x : xs) =
  if not (last xs == x)
  then False
  else isPalindrome (init xs)

isPalindrome' x =
  if x == reverse x then
    True
  else
    False

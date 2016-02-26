--
-- Problem 31: Determine whether a given integer is prime
--
-- Example:
-- *Main> isPrime 7
-- True
-- *Main> isPrime 81
-- False
--
isPrime :: Int -> Bool
isPrime 1 = False
isPrime n = null [x | x <- [2 .. (n - 1)], mod n x == 0]

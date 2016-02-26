--
-- Problem 9: Pack consecutive duplicates of list elements into sublists.
-- If a list contains repeated elements they should be placed in separate
-- sublists.
--
-- Example:
-- *Main> pack [1, 1, 2, 2, 2, 3, 4, 4, 4]
-- [[1,1],[2,2,2],[3],[4,4,4]]
--
auxPack :: (Eq x) => [x] -> [[x]] -> [[x]]
auxPack [] x = x
auxPack (x:xs) [] = auxPack xs [[x]]
auxPack (x:xs) (y:ys) =
  if elem x y then
    auxPack xs ((x:y):ys)
  else
    auxPack xs ([x]:(y:ys))

pack :: (Eq x) => [x] -> [[x]]
pack x = reverse (auxPack x [])

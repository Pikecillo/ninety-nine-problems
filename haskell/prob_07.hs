--
-- Problem 7: Flatten a nested list structure
--
-- Example:
-- *Main> flatten(List[Elem 1, Elem 2, List[], List[Elem 1, Elem 2]])
-- [1,2,1,2]
--
data NestedList x = Elem x | List [NestedList x]
flatten :: NestedList x -> [x]
flatten (Elem x) = [x]
flatten (List []) = []
flatten (List (x : xs)) = flatten x ++ flatten (List xs)

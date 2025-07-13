

data Tuple a b = Tuple
  { tFirst  :: a
  , tSecond :: b
  } deriving (Eq, Show)


data List a =
  Empty
  | Cons a Int (List a)



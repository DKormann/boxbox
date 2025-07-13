module [ID]


ID: Num->Num
ID = |x|
  x


PureHandler: (Num->Num) -> Num
PureHandler = |f|
  f(22)
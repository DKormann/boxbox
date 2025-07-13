app [main!] { pf: platform "https://github.com/roc-lang/basic-cli/releases/download/0.19.0/Hj-J_zxz7V9YurCSTFcFdu6cQJie4guzsPMUi5kBYUk.tar.br" }

import pf.Stdout

main! = |_args|
  Stdout.line!(hh)


pure_handler : (Str -> Str) -> Str
pure_handler = |f| f("hiii")

pp : Str -> Str
pp = |x| x


hh = pure_handler pp

ip! : Str => Str
ip! = |x| x

# ih = pure_handler ip!


d : Int _
d = 22


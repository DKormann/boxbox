
use nom::error::Error;
#[allow(unused_imports)]
#[allow(dead_code)]

use nom::{
  branch::alt, bytes::complete::{tag, take_while1}, character::complete::{alphanumeric1, char, digit1, multispace0, multispace1}, combinator::{map, map_res}, multi::separated_list0, sequence::{delimited, preceded, separated_pair, tuple}, IResult, Parser,

};


// term =
//   | var
//   | int
//   | string
//   | term term # application
//   | !var = term ; term # assignment
//   | λ var term # abstraction
//   | &{term term} # superposition
//   | !&{var var} = term ; term # dublication

// defintion = 
//   | @ name = term # function

// book = defintion*





// #[derive( )]
pub enum Term {
  Var(String),
  Int(i64),
  Str(String),
  App(Box<Term>, Box<Term>),
  Assign(String, Box<Term>, Box<Term>),
  // Abs(String, Box<Term>),
  // Lam(fn(Box<Term>) -> Box<Term>),
  Lam(Box<dyn FnOnce(Term) -> Term>),
  Sup(Box<Term>, Box<Term>),
  Dup(String, String, Box<Term>, Box<Term>),
}





#[derive(Debug, Clone)]
pub struct  Definition {
  name: String,
  value: Term,
}


fn ws<'a, O > (inner: impl Parser<&'a str, Output= O, Error = Error<& 'a str>> ) -> impl Parser<&'a str, Output= O, Error = Error<& 'a str>> 
{
  let res = delimited(multispace0, inner, multispace0);
  res
}


fn abstraction(input: &str) -> IResult<&str, Term>{

  // let p = tuple((tag("λ"), alphanumeric1, multispace1, term));
  let p = (tag("λ"), alphanumeric1, multispace1, term);

  let ff: fn (Box<Term>) -> Box<Term> = |x: Box<Term>| x;

  let mut r = map(p, |(_, var, _, term)| Term::Lam(ff));

  r.parse(input)

}


fn term(input: &str)->IResult<&str, Term>{
  alt((
    abstraction,
  )).parse(input)
}

fn definition(input: &str) -> IResult<&str, Definition> {

  let ff = |s: i32| s;

  let p= preceded(tag("@"), alphanumeric1);
  let res = map(
    p,
    |s: &str| Definition{name: "x".to_string(), value: Term::Var(s.to_string())}
  );
  let mut wp = ws(res);
  
  wp.parse(input)
}



fn book(input: &str) -> IResult<&str, Vec<Definition>> {
  separated_list0(multispace1, definition).parse(input)
}

fn main() {

  let res = book("@hello @world" );
  println!("{:?}", res);
}
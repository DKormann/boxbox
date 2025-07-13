#![allow(unused)]

use syn;
use quote::ToTokens;




fn main() -> Result<(), syn::Error>{

  let args = std::env::args().collect::<Vec<String>>();
  let filecontent = std::fs::read_to_string(&args[1]).unwrap();
  let parsed= syn::parse_file(&filecontent)?;


  println!("code items: {}", parsed.items.len());

  parsed.items.iter().for_each(|x: &syn::Item| {

    let fm = x.to_token_stream().to_string();

    println!("{}", fm);
  }
  
);

  Ok(())
}

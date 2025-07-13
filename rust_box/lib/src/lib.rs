extern crate proc_macro;
use proc_macro::{TokenStream};
use quote::quote;
use syn::{parse_macro_input, ItemFn};


#[proc_macro_attribute]
pub fn main_macro(_attr: TokenStream, item: TokenStream) -> TokenStream {

  let input_fn = parse_macro_input!(item as ItemFn);
  let fn_name = &input_fn.sig.ident;


  if fn_name != "main"{
    return TokenStream::from(quote!{
      compile_error!("This function is not a main function");
    }); 
  };

  TokenStream::from(quote! {#(&input_fn.sig) (|| #(&input_fn.block))()})
}



#[proc_macro_attribute]
pub fn backend_macro(_attr: TokenStream, item: TokenStream) -> TokenStream {
  let input_fn = parse_macro_input!(item as ItemFn);
  let fn_block = &input_fn.block;
  let fn_sig = &input_fn.sig;

  // if &input_fn.sig.ident != "backend"{
  //   return TokenStream::from(quote!{
  //     compile_error!("This function is not a backend function");
  //   });
  // };

  // if (&input_fn.sig).inputs.len() != 2 {
  //   return TokenStream::from(quote!{
  //     compile_error!("wrong arg number");
  //   });
  // }

  TokenStream::from(quote! {#fn_sig { (|| #fn_block)()}})
}


use rust_box_lib::backend_macro;


// #[my_macro]
fn main() {
  println!("Hello, world!");
}





#[backend_macro]
fn backend(_: u32, _: u32) -> u32{
  22
}


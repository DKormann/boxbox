use rust_box_lib::backend_macro;
use serverlib::DBConnection;

fn main() {
  println!("Hello, world!");
}





#[backend_macro]
fn backend(_: u32, _: u32) -> u32{
  22
}



fn accept_message(db: DBConnection, sender: u32, message: String){ 
  db.write(message);
}



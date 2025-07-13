pub struct DBConnection{
  user_id: u32,
}

impl DBConnection{
  pub fn write(&self, message: String){
    println!("user {} sent message {}", self.user_id, message);
  }
}
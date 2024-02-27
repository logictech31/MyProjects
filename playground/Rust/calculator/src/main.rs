use std::io;

fn main() {
    let mut input:String = String::new();
    
    println!("Enter first num: ");
    io::stdin()
    .read_line(&mut input)
    .expect("Cannot take input");
    let num1:i32 = input.parse().unwrap();
    println!("{:?}", num1);
}
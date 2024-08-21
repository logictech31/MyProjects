fn main() -> () {
    let num = 5;
    println!("{:?}", (1..num).fold(|a, b| a * b));
}

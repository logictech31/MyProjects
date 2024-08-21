fn factorial(num: usize) -> usize {
    (1..num).fold(2, |b, a| {
        println!("{a} * {b}");
        a * b
    })
}
fn main() -> () {
    let num = 5;
    println!("{:?}", factorial(num + 1));
}

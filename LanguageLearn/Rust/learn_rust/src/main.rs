use std::io;

pub mod garden;

fn ret_two_vals() -> (i16, i16) {
    return (10, 5);
}

fn data_types() -> i32 {
    let number: i32 = 23123;
    let tup: (i32, f64, &str) = (440, 23.3, "Hello World");

    println!("{}", number);

    let four_forty = tup.0;
    let twenty_three_pt_three = tup.1;
    let msg = tup.2;

    println!("{four_forty}\t{twenty_three_pt_three}\t{msg}");
    
    return number;
}

fn shadowing() {
    let x: i8 = -33;

    let x: i8 = x % 10;

    println!("{x}");
}

fn main() {
    let mut input: String = String::new();
    println!("Enter a number: ");

    io::stdin().read_line(&mut input).expect("Error taking input!");

    let retval = data_types();

    println!("{retval}");

    shadowing();

    let (a, b) = ret_two_vals();

    println!("{a} {b}");
}



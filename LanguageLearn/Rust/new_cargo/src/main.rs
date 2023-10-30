use std::io;
use rand::Rng;

fn main() {
    let mut guess = String::new();
    let num: u32 = guess.trim().parse().expect("Failed to execute rand");

    println!("Guess the number: ");
    println!("Please input your guess: ");

    io::stdin()
        .read_line(&mut guess)
        .expect("Failed to take input");

    println!("Your guess is {guess}");
}

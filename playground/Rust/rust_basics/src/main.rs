use std::io;
fn input_output_parsing() {
    let mut input:String = String::new();
    println!("Enter some data: ");
    io::stdin()
    .read_line(&mut input)
    .expect("cannot take input");

    let intinp = input.trim().parse::<i32>().expect("Cannot parse for some reason.");
    println!("{}", intinp);
}

fn different_control_conditions() {
    // We will be checking out on regular if, if-let and match
    // First we will go with regular if

    let a = 3;
    let b = 4;
    let option_type: Option<i32> = Some(5);
    let option_type_2: Option<i32> = None;
    let num: u32 = 15;

    if a == b {
        println!("EQUAL!")
    } else {
        println!("{} not equal to {}", a, b);
    }

    // the if-let destructs the value from Some() datatype
    // It will go to else condition if there is 'None' value
    if let Some(i) = option_type {
        println!("Destructed val => {}", i);
    }

    if let Some(i) = option_type_2 {
        println!("Destructed val => {}", i);
    } else {
        println!("Value \'None\' is present");
    }

    match num {
        1 => println!("One"),
        // Matching several values
        2 | 3 | 5 | 7 | 9 | 11 => println!("Idk"),
        31 => println!("Birthdate"),
        // Range inclusive
        13..=19 => println!("13 to 19 somewhere"),
        _ => println!("Random?")
    }
    
}

fn datatypes_structs() {
    let tup1: (i32, f32) = (1, 1.5);

    for x in tup1 {
        println!("{x}");
    }
}

fn main() {
    input_output_parsing();
    different_control_conditions();
    datatypes_structs();
}

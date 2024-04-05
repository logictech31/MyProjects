use std::io;

fn main() {
    let mut continue_calc:String = String::from("");
    loop {
        /* 
            Get the first number here and parse it
        */
        let mut input = String::from("");
        print!("Enter first number: ");
        io::stdin()
        .read_line(&mut input)
        .expect("Cannot read input!");
        
        let num1 = input.parse::<i32>();

        if let Ok(val) = num1 {
            let num1 = val;
        } else {
            println!("Error parsing the value");
            return;
        }
        /* 
            Get the second number here and parse it
        */
        print!("Enter second number: ");
        io::stdin()
        .read_line(&mut input)
        .expect("Cannot read input!");
        
        let num2 = input.parse::<i32>();
        
        if let Ok(val) = num2 {
            let num2 = val;
        } else {
            println!("Error parsing the value");
            return;
        }
        /* 
            Get the operation number here and parse it
        */
        println!("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\nChoice: ");
        io::stdin()
        .read_line(&mut input)
        .expect("Cannot take input.");

        let operation = input.parse::<u32>();

        if let Ok(val) = operation {
            let operation = val;
        } else {
            return;
        }

        match operation {
            Ok(1) => {
                let result = num1 + num2;
                println!("Result is: {}", result);
            }

            Ok(2) => {
                println!("Result is: ")
            }
            _ => {
                println!("Invalid operation!");
            }
        }

        print!("Do you want to continue?\nChoice(y/N): ");
        io::stdin()
        .read_line(&mut continue_calc)
        .expect("Cannot take input.");
        if continue_calc.eq("n") {
            return;
        }
    };
}
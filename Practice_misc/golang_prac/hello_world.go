package main

import (
	"fmt"
	"time"
)

func routine_1() {
	fmt.Println("\nHello Routine 1!")
}

func routine_2() {
	fmt.Println("\nHello World!")
}

func main() {
	fmt.Print("Checking Go routine at ", time.Now())
	go routine_1()
	go routine_2()
	time.Sleep(time.Second)

	fmt.Println("Ending program")
}

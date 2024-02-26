package main

import "fmt"

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	var reverse int

	for copy := x; copy > 0; copy /= 10 {
		reverse = reverse*10 + copy%10
	}

	return x == reverse
}

func main() {
	x := 1
	output := isPalindrome(x)
	fmt.Println(output)
}

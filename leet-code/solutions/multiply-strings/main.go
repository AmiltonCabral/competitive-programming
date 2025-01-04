package main

import (
	"strconv"
)

func multiply(num1 string, num2 string) (ans string) {
	if num1 == "0" || num2 == "0" {
		return "0"
	}

	result := make([]int, len(num1)+len(num2))

	for i := len(num1) - 1; i >= 0; i-- {
		for j := len(num2) - 1; j >= 0; j-- {
			mul := int(num1[i]-'0') * int(num2[j]-'0')
			sum := result[i+j+1] + mul
			result[i+j+1] = sum % 10
			result[i+j] += sum / 10
		}
	}

	for _, val := range result {
		ans += strconv.Itoa(val)
		if ans == "0" {
			ans = ""
		}
	}

	return
}

func main() {
	num1 := "45"
	num2 := "123"
	println(multiply(num1, num2))
}

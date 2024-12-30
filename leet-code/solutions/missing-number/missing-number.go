package main

import "fmt"

func missingNumber(nums []int) int {
	sum := 0

	for i, val := range nums {
		sum += i + 1
		sum -= val
	}

	return sum
}

func main() {
	nums := []int{3, 0, 1}
	result := missingNumber(nums)
	fmt.Println(result)
}

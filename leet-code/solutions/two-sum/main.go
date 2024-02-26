package main

import "fmt"

func twoSum(nums []int, target int) []int {
	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i]+nums[j] == target {
				return []int{i, j}
			}
		}
	}

	return []int{0, 1}
}

func main() {
	nums := []int{-3, 4, 3, 90}
	target := 0
	result := twoSum(nums, target)
	fmt.Println(result)
}

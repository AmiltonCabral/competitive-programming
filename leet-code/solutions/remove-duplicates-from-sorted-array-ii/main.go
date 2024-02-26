package main

import "fmt"

func removeDuplicates(nums []int) int {
	k := 0
	actual := nums[0]
	rep := 0

	for i := 0; i < len(nums); i++ {
		nums[k] = nums[i]

		if nums[i] == actual {
			rep++
		} else {
			rep = 1
			actual = nums[i]
		}

		if rep < 3 {
			k++
		}

	}

	return k
}

func main() {
	nums := []int{1, 1, 1, 2, 2, 3}
	k := removeDuplicates(nums)
	fmt.Println(k, nums)
}

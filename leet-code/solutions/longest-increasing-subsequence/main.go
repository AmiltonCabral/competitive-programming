package main

import "fmt"

// 1-D Dynamic Programming
// Time: O(n^2)
// Space: O(n)
func lengthOfLIS(nums []int) (ans int) {
	n := len(nums)
	dp := make([]int, n)

	for i := n - 1; i >= 0; i-- {
		dp[i] = 1

		for j := i + 1; j < n; j++ {
			if nums[i] < nums[j] {
				dp[i] = max(dp[i], 1+dp[j])
			}
		}

		ans = max(ans, dp[i])
	}

	return ans
}

func main() {
	nums := []int{10, 9, 2, 5, 3, 7, 101, 18}
	result := lengthOfLIS(nums)
	fmt.Println(result)
}

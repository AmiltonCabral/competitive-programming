package main

import "fmt"

func lengthOfLongestSubstring(s string) int {
	seenChars := make(map[byte]int)
	var maxLength, left int

	for right := 0; right < len(s); right++ {
		if index, seen := seenChars[s[right]]; seen && index >= left {
			left = index + 1
		}
		seenChars[s[right]] = right
		length := right - left + 1
		if length > maxLength {
			maxLength = length
		}
	}

	return maxLength
}

func main() {
	substrig := "abc"
	result := lengthOfLongestSubstring(substrig)
	fmt.Println(result)
}

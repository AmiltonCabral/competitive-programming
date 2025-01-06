package main

import "fmt"

// Time: O(n)
// Space: O(n)
// Not optimal, can be done with Time=O(n) and Space=O(1) with greedy approach
func checkValidString(s string) bool {
	var left, star []int

	for i := 0; i < len(s); i++ {
		switch ch := s[i]; ch {
		case '*':
			star = append(star, i)
		case '(':
			left = append(left, i)
		case ')':
			if len(left) > 0 {
				left = left[:len(left)-1]
			} else if len(star) > 0 {
				star = star[:len(star)-1]
			} else {
				return false
			}
		}
	}

	for len(left) > 0 && len(star) > 0 {
		if left[len(left)-1] > star[len(star)-1] {
			return false
		}
		left = left[:len(left)-1]
		star = star[:len(star)-1]
	}

	return len(left) == 0
}

func main() {
	s := "((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()"
	result := checkValidString(s)
	fmt.Println(result)
}

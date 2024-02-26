package main

import "fmt"

func merge(nums1 []int, m int, nums2 []int, n int)  {
	aux := make([]int, m)
	i := 0
	j := 0
	k := 0
	copy(aux[:], nums1[0:m])

	for i < m && j < n {
		if aux[i] < nums2[j] {
			nums1[k] = aux[i]
			i++
		} else {
			nums1[k] = nums2[j]
			j++
		}
		k++
	}

	for i < m {
		nums1[k] = aux[i]
		i++
		k++
	}

	for j < n {
		nums1[k] = nums2[j]
		j++
		k++
	}
}

func main() {
	nums1 := []int{1,2,3,0,0,0}
	nums2 := []int{2,5,6}
	m := 3
	n := 3
	merge(nums1, m, nums2, n)
	fmt.Println(nums1)
}
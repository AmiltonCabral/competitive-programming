package main

import "fmt"

// Cria-se um array auxiliar (aux) ordenado com valores de nums1 e nums2.
// Esse array auxiliar é criado até a metade (mid).
// Caso m+n seja impar, é retornado o último valor de aux.
// Caso m+n seja par, é retornado a media dos dois ultimos valores de aux.

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	m, n := len(nums1), len(nums2)
	mid := ((m + n) / 2) + 1
	aux := make([]int, mid)

	for k, i, j := 0, 0, 0; k < mid; k++ {
		if i < m && (j == n || nums1[i] < nums2[j]) {
			aux[k] = nums1[i]
			i++
		} else {
			aux[k] = nums2[j]
			j++
		}
	}

	if (m+n)%2 == 0 {
		return float64(aux[mid-1]+aux[mid-2]) / 2
	}
	return float64(aux[mid-1])
}

// ao invez de criar um array auxiliar novo grande, cria duas variaveis p1 e p2.
// p1 e p2 armazena os ultimos menores valores acessados de nums1 e nums2.
// caso m+n seja impar, retorna a ultima variavel modificada entre p1 e p2.
// caso m+n seja par, retorna a media de p1 e p2.

func findMedianSortedArrays2(nums1 []int, nums2 []int) float64 {
	m, n := len(nums1), len(nums2)
	aux := [2]int{}
	k := 0

	for i, j, mid := 0, 0, ((m+n)/2)+1; i+j < mid; k = 1 - k {
		if i < m && (j == n || nums1[i] < nums2[j]) {
			aux[k] = nums1[i]
			i++
		} else {
			aux[k] = nums2[j]
			j++
		}
	}

	if (m+n)%2 == 0 {
		return float64(aux[0]+aux[1]) / 2
	}
	return float64(aux[1-k])
}

func main() {
	nums1 := []int{1, 3}
	nums2 := []int{2}
	result := findMedianSortedArrays2(nums1, nums2)
	fmt.Println(result)
}

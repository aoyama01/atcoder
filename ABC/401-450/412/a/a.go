package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	sum := 0

	for i := 0; i < n; i++ {
		sum += a[i]
	}

	if sum <= m {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

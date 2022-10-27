package main

import (
	"fmt"
)

func lcm(x, y int64) int64 {
	var m int64 = x * y
	var i = x
	if x < y {
		i = y
	}
	for ; i <= m; i++ {
		if i%x == 0 && i%y == 0 {
			return i
		}
	}
	if m < 0 {
		m = -m
	}
	return m
}

func main() {
	var x, y int64
	fmt.Println("Please input two numbers:")
	fmt.Scanf("%d %d", &x, &y)
	fmt.Println("最小公倍数LCM=", lcm(x, y))
}

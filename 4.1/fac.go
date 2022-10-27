package main

import (
	"fmt"
	"math/big"
)

func factorial(n *big.Int) *big.Int {
	if n.Int64() == 1 {
		return big.NewInt(1)
	} else {
		return n.Mul(n, factorial(big.NewInt(n.Int64()-1)))
	}
}

func main() {
	var i int64
	fmt.Println("Please input a number:")
	fmt.Scanf("%d", &i)
	fmt.Printf("The factorial is %d", factorial(big.NewInt(i)))
}

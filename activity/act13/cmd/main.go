package main

import (
	"fmt"
	"os"
)

func main() {
	secretUser := os.Getenv("secret_user")
	fmt.Printf("Hello, %s\n", secretUser)
}

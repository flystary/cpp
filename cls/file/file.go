package main


import "fmt"


type Person struct {
    Name string
    Age  int
}


func main() {
    person := Person {
        Name: "test",
        Age: 15,
    }

    fmt.Printf("%v\n", person)
    fmt.Printf("%+v\n", person)
    fmt.Printf("%#v\n", person)
}


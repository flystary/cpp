#!/bin/python3

class A:
    def __init__(self, name, age):
        self.name = name
        self.age  = age

    def print_age(self):
        print(self.age)

    def print_name(self):
        print(self.name)


class B(A):
     def __init__(self, name, age, mode):
        super(B, self).__init__(name, age)
        self.mode = mode

     def print_mode(self):
        print(self.name, self.age, self.mode)


b = B("liql", 234, "xci")


b.print_age()
b.print_name()
b.print_mode()

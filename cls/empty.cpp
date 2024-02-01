#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


class emptyClassA
{

};


class emptyClassB
{
    static int i;
};


class emptyClassC
{
    void func1() {};

    void func2() {};
};


int main()
{
    cout << "A: " << sizeof(emptyClassA) << endl;
    cout << "B: " << sizeof(emptyClassB) << endl;
    cout << "C: " << sizeof(emptyClassC) << endl;

    return 0;
}

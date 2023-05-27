#include <iostream>

using namespace std;

double division(int a, int b)
{
    if (b == 0)
    {
        throw "Division by zero condition";
    }

    return (a/b);
}

int try_1()
{
    double s;

    // s =  division(2, 0);
    // cout << s << endl;

    s =  division(2, 8);
    cout << s << endl;

    return 0;
}

double div(int a, int b);

int try_2()
{
    int x, y;
    double z;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;

    try {
        z = div(x, y);
        cout << " x / y : ";
        cout << z << endl;
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;
}

double div(int a, int b)
{
    if (b == 0)
    {
        throw "div by zero!";
    }
    return (a / b);
}

#include <exception>
struct MyException : public exception
{
    const char * what () const throw ()
    {
        return "C++ Exception";
    }
};

int try_3()
{
    try {
        throw MyException();
    }
    catch(MyException& e)
    {
        cout << "MyException caught" << endl;
        cout << e.what() << endl;
    }

    catch(std::exception& e)
    {
        //other error
    }
}

int main()
{
    try_1();
    try_2();
    try_3();

    return 0;
}

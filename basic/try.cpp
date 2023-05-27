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

int main()
{
    try_2();

    return 0;
}

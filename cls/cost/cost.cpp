#include<iostream>

using namespace std;

int main()
{
    const int num = 100;
    cout << "num = " << num << endl;
    
    int *p = (int *)& num;

    *p = 200;

    cout << "num = " << num << endl;
    cout << "*p= " << *p << endl;
    cout << "p= " << p << endl;
    cout << "&num= " << &num << endl;
    
    return 0;
}

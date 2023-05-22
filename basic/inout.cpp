#include <iostream>
using namespace std;


int out()
{
    char str[] = "Hello C++";
    cout << "Value of str is : " << str << endl;

    return 0;
}

int in()
{
    char name[50];
    cout << "name: ";
    cin >> name;

    cout << "You name is: " << name << endl;
    
    return 0;
}

int err()
{
    char str[] = "Unable to read....";
    cerr << "Error message: " << str << endl;

    return 0;
}

int log()
{
    char str[]  = "Unable to read....";
    clog << "Error Message: " <<  str << endl;

    return 0;
}

int main()
{
    out();
    in();

    err();
    log();

    return 0;
}

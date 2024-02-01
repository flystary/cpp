#include <iostream>
using namespace std;

class A
{
    public:
    static int share;
};


int A::share = 5;

int main()
{
    A x;

    cout << A::share << endl;
    cout << x.share << " " <<endl;

    return 0;   
}

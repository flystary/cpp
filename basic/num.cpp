#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int num()
{
    short   s;
    int     i;
    long    l;
    float   f;
    double  d;
    

    s = 10;      
    i = 1000;    
    l = 1000000; 
    f = 230.47;  
    d = 30949.374;

    cout << "short  s :" << s << endl;
    cout << "int    i :" << i << endl;
    cout << "long   l :" << l << endl;
    cout << "float  f :" << f << endl;
    cout << "double d :" << d << endl;
 
    return 0;
}

int num_1()
{
    short   s = 10;
    int     i = -1000;
    long    l = 100000;
    float   f = 230.47;
    double  d = 200.374;

    cout << "sin(d) :" << sin(d) << endl;
    cout << "abs(i)  :" << abs(i) << endl;
    cout << "floor(d) :" << floor(d) << endl;
    cout << "sqrt(f) :" << sqrt(f) << endl;
    cout << "pow( d, 2) :" << pow(d, 2) << endl;

    return 0;
}

int num_2()
{
    int i, j;
    srand( (unsigned)time(NULL));

    for(i = 0; i < 10; i++)
    {
        j = rand();
        cout << "随机数: " << j << endl;
    }

    return 0;
}
int main()
{
    num();
    cout << "\n";
    num_1();
    cout << "\n";
    num_2();
    cout << "\n";

    return 0;
}

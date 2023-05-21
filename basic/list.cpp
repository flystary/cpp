#include <iostream>
using namespace std;

// type arrayName [arraySize];

int list() {
    double balance[10];

    double balance1[5] =  {1000.0, 2.0, 3.4, 7.0, 50.0};
    double balance2[] =  {1000.0, 2.0, 3.4, 7.0, 50.0};
}
#include <iomanip>
using std::setw;

int list_1()
{
    int n[10];

    for (int i = 0; i < 10; i++)
    {
        n[i] = i + 100;
    }
    cout << "Element" << setw(13) << "Value" << endl;


    for (int j = 0; j < 10; j++)
    {
        cout << setw(7) << j << setw(13) << n[j] << endl;
    }

    return 0;
} 

int main()
{
    list_1();

    return 0;
}

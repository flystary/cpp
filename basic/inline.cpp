#include <iostream>

using namespace std;

inline int Max(int x, int y)
{
    return (x > y) ? x : y;
}

int inl()
{
   cout << "Max (20,10): " << Max(20,10) << endl;
   cout << "Max (0,200): " << Max(0,200) << endl;
   cout << "Max (200,200): " << Max(200,200) << endl;
   cout << "Max (100,1010): " << Max(100,1010) << endl;
   return 0;
}

int main()
{
    inl();

    return 0;
}

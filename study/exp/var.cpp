#include <iostream>
using namespace std;

int g = 20;


int var()
{
    int a = 10;
    {
        int a = 20;
        cout << "块: " << a << endl;
    }
    cout << "外部: " << a << endl;

    return 0;
}


class My {
public:
    static int class_var;
};
int My::class_var = 30;

int var_1()
{
    cout << "类变量: " << My::class_var << endl;

    return 0;
}

int main()
{
    // int g = 10;

    // cout << g << endl;
    
    var();

    var_1();

    return 0;
}

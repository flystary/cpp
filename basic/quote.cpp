#include <iostream>
using namespace std;

// 不存在空引用。引用必须连接到一块合法的内存。
// 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
// 引用必须在创建时被初始化。指针可以在任何时间被初始化。
//

// int i = 7;
// int& r = i;
// double& s = d;
//

int quote()
{
    int     i;
    double  d;

    int&    r = i;
    double& s = d;

    i = 5;
    cout << "Value of i : " << i << endl;
    cout << "Value of i reference : " << r  << endl;
 
    d = 11.7;
    cout << "Value of d : " << d << endl;
    cout << "Value of d reference : " << s  << endl;
   
    return 0;
}


int main()
{
    quote();

    return 0;
}

#include <iostream>

using namespace std;
/*
 *void cls()
 *{
 *   auto f = 3.14;
 *   auto s("hello");
 *   auto z = new auto(9);
 *   auto x1 = 5, x2 = 5.0, x3 = 'r';
 *}
 */

void func(void);
 
static int count = 10; /* 全局变量 */
 
int cls_1()
{
    while(count--)
    {
       func();
    }
    return 0;
}

void func( void )
{
    static int i = 5; // 局部静态变量
    i++;
    std::cout << "变量 i 为 " << i ;
    std::cout << " , 变量 count 为 " << count << std::endl;
}

thread_local int x;  // 命名空间下的全局变量
class X
{
    static thread_local std::string s; // 类的static成员变量
};

static thread_local std::string X::s;  // X::s 是需要定义的
 
void foo()
{
    thread_local std::vector<int> v;  // 本地变量
}

int main()
{
    cls_1();

    return 0;
}

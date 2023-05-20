#include <iostream>
using namespace std;

int stype()
{
    signed int num1 = -10; // 定义有符号整型变量 num1，初始值为 -10
    unsigned int num2 = 20; // 定义无符号整型变量 num2，初始值为 20
    short int num3 = 10; // 定义短整型变量 num1，初始值为 10
    long int num4 = 100000; // 定义长整型变量 num2，初始值为 100000
    long long int num5 = 10000000000; // 定义长长整型变量 num1，初始值为 10000000000
    float num6 = 3.14f; // 定义单精度浮点数变量 num1，初始值为 3.14
    double num7 = 2.71828; // 定义双精度浮点数变量 num2，初始值为 2.71828
    bool flag = true; // 定义布尔类型变量 flag，初始值为 true
    char ch1 = 'a'; // 定义字符类型变量 ch1，初始值为 'a'
    wchar_t ch2 = L'你'; // 定义宽字符类型变量 ch2，初始值为 '你'

    return 0;
}

#define NEWLINE  "\n"
int stype_1()
{
    short int i;
    short unsigned int j;

    j = 50000;
    i = j;

    cout << i << " " << j;

    return 0;
}

class Ex {
public:
    int get_value() const {
        return value_;
    }
    void set_value(int value) const {
        value_ = value;
    }

private:
    mutable int value_;
};


void example_func()
{
    static int count = 0;
    count++;
}

void example_func1(register int num) {}

void stype_2()
{   
    const int NUM = 10;
    const int* ptr = &NUM;
    int const* ptr2 = &NUM;

    
    volatile int num = 20;
    
    example_func();
   //  example_func1();
}

int main()
{
    stype_1();
    cout << NEWLINE;
    stype_2();
    
    return 0;
}

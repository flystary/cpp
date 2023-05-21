#include <iostream>

using namespace std;

int point()
{
    int     var1;
    char    var2[10];


    cout << "var1: " << &var1 << endl;
    cout << "var2: " << &var2 << endl;

    return 0;
}


// int    *ip;    /* 一个整型的指针 */
// double *dp;    /* 一个 double 型的指针 */
// float  *fp;    /* 一个浮点型的指针 */
// char   *ch;    /* 一个字符型的指针 */

int point_1()
{
    int var = 20;
    int *ip;

    ip = &var;
    cout << "Value: " << var << endl;

    cout << "Address: " << ip << endl;

    cout << "Value of *ip: " << *ip << endl;

    return 0;
}

int point_2()
{
    int *ptr = NULL;
    cout << "ptr: " << ptr;

    return 0;
}


// if(ptr)     /* 如果 ptr 非空，则完成 */
// if(!ptr)    /* 如果 ptr 为空，则完成 */
//

const int MAX = 3;

int point_3()
{
    int var[MAX] = {10, 100, 200};
    int *ptr;

    ptr = var;
    for (int i = 0; i < MAX; i++)
    {
        cout << "Address of var[" << i << "]= ";
        cout << ptr <<  endl;

        cout << "Value of var[" << i << "] = ";
        cout << *ptr << endl;

        ptr++;
    }

    return 0;
}

int point_4()
{
    int  var[MAX] = {10, 100, 200};
    int  *ptr;

    ptr = &var[MAX-1];
    for (int i = MAX; i > 0; i--)
    {
        cout << "Address of var[" << i << "] = ";
        cout << ptr << endl;
 
        cout << "Value of var[" << i << "] = ";
        cout << *ptr << endl;
        ptr--;
    }

    return 0;
}

int point_5()
{
    int  var[MAX] = {10, 100, 200};
    int  *ptr;

       ptr = var;
   int i = 0;
   while ( ptr <= &var[MAX - 1] )
   {
      cout << "Address of var[" << i << "] = ";
      cout << ptr << endl;
 
      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl;
 
      // 指向上一个位置
      ptr++;
      i++;
    }
    return 0;
}


int point_6()
{
    int  var[MAX] = {10, 100, 200};
 
    for (int i = 0; i < MAX; i++)
    {
        *var = i;    // 这是正确的语法
       // var++;       // 这是不正确的
    }
    return 0;
}

// *(var +2) = 500;

int main()
{
    point();
    cout << "\n";

    point_1();
    cout << "\n";

    point_3();
    cout << "\n";

    point_4();
    cout << "\n";

    point_5();
    cout << "\n";

    point_6();
    cout << "\n";

    return 0;   
}

#include <iostream>
#include <string>


using namespace std;


int cons()
{
    string greeting = "hello world";
    cout << greeting << endl;

    cout << "\n";
    string greeting2 = "hello, \
                        baidu";

    cout << greeting2 << endl;

    return 0;

}

#define LENGTH 10
#define WHDTH   5
#define NEWLINE '\n'

int cons_1()
{
    int area;
    area = LENGTH * WHDTH;
    cout << area;
    cout << NEWLINE;
    cout << NEWLINE;

    return 0;
}

int cons_2()
{
   const int  LENGTH1 = 5;
   const int  WIDTH1  = 5;
   const char NEWLINE1 = '\n';
   int area;  
   
   area = LENGTH1 * WIDTH1;
   cout << area;
   cout << NEWLINE1;
   return 0;
}


int main()
{
    cons();
    cout << NEWLINE;
    cons_1();
    cout << NEWLINE;
    cons_2();

    return 0;
}

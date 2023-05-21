#include <iostream>

using namespace std;


int opera()
{
    int a = 21;
    int b = 10;
    int c;

    c = a + b;
    cout << "a + b: " << c << endl;
    c = a - b;
    cout << "a - b: " << c << endl;
    c = a * b;
    cout << "a * b: " << c << endl;
    c = a / b;
    cout << "a / b: " << c << endl;
    c = a % b;
    cout << "a %% b: " << c << endl;
    
    int d = 10;
    c = d++;
    cout << "d++ " << c << endl;

    d = 10;
    c = d--;
    cout << "d-- " << c << endl;
    
    return 0;
}

int opera_1()
{
    int a = 21;
    int b = 10;
    int c;

    if( a == b )
   {
      cout << "Line 1 - a 等于 b" << endl ;
   }
   else
   {
      cout << "Line 1 - a 不等于 b" << endl ;
   }
   if ( a < b )
   {
      cout << "Line 2 - a 小于 b" << endl ;
   }
   else
   {
      cout << "Line 2 - a 不小于 b" << endl ;
   }
   if ( a > b )
   {
      cout << "Line 3 - a 大于 b" << endl ;
   }
   else
   {
      cout << "Line 3 - a 不大于 b" << endl ;
   }
   /* 改变 a 和 b 的值 */
   a = 5;
   b = 20;
   if ( a <= b )
   {
      cout << "Line 4 - a 小于或等于 b" << endl ;
   }
   if ( b >= a )
   {
      cout << "Line 5 - b 大于或等于 a" << endl ;
   }
   return 0;
}

int opera_2()
{
    int a = 5;
   int b = 20;
   int c ;
 
   if ( a && b )
   {
      cout << "Line 1 - 条件为真"<< endl ;
   }
   if ( a || b )
   {
      cout << "Line 2 - 条件为真"<< endl ;
   }
   /* 改变 a 和 b 的值 */
   a = 0;
   b = 10;
   if ( a && b )
   {
      cout << "Line 3 - 条件为真"<< endl ;
   }
   else
   {
      cout << "Line 4 - 条件不为真"<< endl ;
   }
   if ( !(a && b) )
   {
      cout << "Line 5 - 条件为真"<< endl ;
   }
   return 0;
}

int opera_3()
{
    unsigned int a = 60;      // 60 = 0011 1100  
   unsigned int b = 13;      // 13 = 0000 1101
   int c = 0;           
 
   c = a & b;             // 12 = 0000 1100
   cout << " a & b 的值是 " << c << endl ;
 
   c = a | b;             // 61 = 0011 1101
   cout << " a | b 的值是 " << c << endl ;
 
   c = a ^ b;             // 49 = 0011 0001
   cout << " a ^ b 的值是 " << c << endl ;
 
   c = ~a;                // -61 = 1100 0011
   cout << " ~a 的值是 " << c << endl ;
 
   c = a << 2;            // 240 = 1111 0000
   cout << " a << 2 的值是 " << c << endl ;
 
   c = a >> 2;            // 15 = 0000 1111
   cout << " a >> 2 的值是 " << c << endl ;
 
   return 0;
}

int opera_4()
{
    int a = 21;
    int c ;

    c =  a;
    cout << " c = a : " <<c<< endl ;
 
    c +=  a;
    cout << " c += a : " <<c<< endl ;
 
    c -=  a;
    cout << " c -= a : " <<c<< endl ;
 
    c *=  a;
    cout << " c *= a : " <<c<< endl ;
 
    c /=  a;
    cout << " c /= a : " <<c<< endl ;
 
    c  = 200;
    c %=  a;
    cout << " c %= a : " <<c<< endl ;
 
    c <<=  2;
    cout << " c <<= 2 : " <<c<< endl ;
 
    c >>=  2;
    cout << " c >>= 2 : " <<c<< endl ;
 
    c &=  2;
    cout << " c &= 2 : " <<c<< endl ;
 
    c ^=  2;
    cout << " c ^= 2 : " <<c<< endl ;
 
    c |=  2;
    cout << " c |= 2: " <<c<< endl ;
 
    return 0;
}

int opera_5() 
{
    int a = 20;
    int b = 10;
    int c = 15;
    int d = 5;
    int e;
    
    cout << "a b c d ";
    cout << " " << a;
    cout << " " << b;
    cout << " " << c;
    cout << " " << d;
    cout << endl;
 
    e = (a + b) * c / d;      // ( 30 * 15 ) / 5
    cout << "(a + b) * c / d 的值是 " << e << endl ;
 
    e = ((a + b) * c) / d;    // (30 * 15 ) / 5
    cout << "((a + b) * c) / d 的值是 " << e << endl ;
 
    e = (a + b) * (c / d);   // (30) * (15/5)
    cout << "(a + b) * (c / d) 的值是 " << e << endl ;
 
    e = a + (b * c) / d;     //  20 + (150/5)
    cout << "a + (b * c) / d 的值是 " << e << endl ;
  
    return 0;
}

int main()
{
    opera();
    cout << "\n";

    opera_1();
    cout << "\n";

    opera_2();
    cout << "\n";

    opera_3();
    cout << "\n";

    opera_4();
    cout << "\n";

    opera_5();

    return 0;
}

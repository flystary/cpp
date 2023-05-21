#include <iostream>

using namespace std;

/*
int loop()
{
   for( ; ; )
   {
      printf("This loop will run forever.\n");
   }
 
   return 0;
}
*/

int loop_1()
{
    for(int i; i < 10; i++)
    {
        cout << " " <<  i;
    }
}

int main()
{
    // loop();
    loop_1();
    cout << "\n";


    return 0;
}

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;


int stl()
{
    vector<int> vec;
    int     i;


    cout << "vector size = " << vec.size() << endl;
    printf("sizeof : %d\n", sizeof(vec));

    for(i = 0; i < 5; i++) {
       vec.push_back(i);
    }

    cout << "extended vector size = " << vec.size() << endl;
    printf("sizeof : %d\n", sizeof(vec));

    for( i = 0; i < 5; i++) {
        cout << "Value of vec [" << i << "]" << vec[i] << endl;
    }

    vector<int>::iterator v = vec.begin();
    //while(v != vec.end()) {
    //    cout << "value of v = " << *v << endl;
    //    v++;
    //}

    for (i = 0 ; i < 10; i++) {
        cout << *v << endl;
        printf("%d ---- %d \n", *v, sizeof(*v));
        v++;
    }

    return 0;
}

int main()
{
    stl();

    return 0;
}

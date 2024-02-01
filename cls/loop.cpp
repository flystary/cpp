#include <iostream>
#include <vector>

using namespace std;



int loop()
{
    vector<uint32_t> vec;

    for(int i=0; i<10000000; i++)
    {
        vec.push_back(i);
    }

    for(int i=0; i<1000; i++)
    {
        uint64_t sum = 0;
        for(vector<uint32_t>::const_iterator itr = vec.begin();
            itr != vec.end();
            itr++)
        {
            sum += *itr;
        }
        cout << sum << endl;
    }
    return 0;
}


int loop1()
{
    vector<uint32_t> vec;
    for(int i=0; i<10000000; i++)
    {
        vec.push_back(i);
    }


    for(int i=0; i<1000; i++)
    {
        uint64_t sum = 0;
        vector<uint32_t>::const_iterator itr, end(vec.end());
        for(itr = vec.begin(); itr != end; itr++)
        {
            sum += *itr;
        }
        cout << sum << endl;
    }

    return 0;
}


int main()
{
    // loop();
    loop1();

    return 0;
}   

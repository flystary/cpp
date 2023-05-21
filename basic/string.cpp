#include <iostream>
#include <string>


using namespace std;

int str()
{
    string str1 = "baidu";
    string str2 = "google";
    string str3;
    int len;

    str3 = str1;
    cout << "str3: "  << str3 << endl;

    str3 = str1 + str2;
    cout << "str1 + str2 : " << str3 << endl;

    len = str3.size();
    cout << "str3.size() : " << len << endl;

    return 0;
}

int main()
{
    str();

    return 0;
}

#include <iostream>
#include <json/json.h>


using namespace std;


std::string jsonToString()
{
    Json::FastWriter wrInfo;
    Json::Value      wrValue;


    wrValue["name"] = "xiaomi";
    wrValue["age"]  = 9;

    std::string str1 = wrInfo.write(wrValue);

    return str1;
}


int main()
{
    std::string output = jsonToString();
    cout << output << endl;

    Json::StyledWriter sw;
    cout << sw.write(output) << endl;

    return 0;
}

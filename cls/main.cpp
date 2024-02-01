//

#include <iostream>
#include <pcrecpp.h>
#include <string>
#include "stdio.h"
#include "string_u.h"
#include "ipv4_u.h"

using namespace std;


int main() {
    // const string b = "hello world good";
    // const string s = "hellogood";
    // const string d = "C++";

    // const string str1 = strReplace(b, s, d); 
    // printf("%s\n", str1.c_str());
    /*
    vector<string> vs;
    vector<string> vs1;

    strSplit(b, vs, "");
    for (int i = 0; i < vs.size(); i++) {
        printf("%s\n", vs[i].c_str());
    }

    cout << endl;
    strSplit(s, vs1, " ");
    for (int i = 0; i < vs1.size(); i++) {
        printf("%s\n", vs[i].c_str());
    }
    */

    // const string src = "10.168.1.1/24";
    // int   num;
    // num = ipv4_to_int(src);

    // printf("%s to %d\n", src.c_str(), num);
    // printf("%d to %s\n", num, int_to_ipv4(num).c_str());
    
    // string prefix = "24";
    // cout << "prefix: " << prefix << endl;

    // unsigned int intprefix = prefix_to_int(prefix);
    // cout << intprefix << endl;

    // string  netmask = prefix_to_netmask(prefix);
    // cout << netmask << endl;
    //

    const string ipstr = "172.16.30.1";
    unsigned int num = ipv4_to_int(ipstr);
    cout << num << endl;

    string uuidStr = uuidGenerate();
    cout << "uuid: " <<  uuidStr << endl;;       

    return 0;    
}

#include "ipv4_u.h"
#include "string_u.h"

using std::to_string;
using std::vector;

string int_to_ipv4(unsigned int intIPv4) {
    return to_string(((intIPv4 >> 24) & 0xFF)) + "." + to_string(((intIPv4 >> 16) & 0xFF)) + "." + to_string(((intIPv4 >> 8) & 0xFF)) + "." + to_string((intIPv4 & 0xFF));
}

unsigned int ipv4_to_int(string ipv4) {
    vector<string> intVector;
    strSplit(ipv4, intVector, ".");

    if (intVector.size() != 4) {
        return 0;
    }
    unsigned int result = 0;
    for ( int i =0; i < 4; i++) {
        result += atoi(intVector[i].c_str()) << (8 * (3 - i));
    }

    return result;
}

unsigned int prefix_to_int(string prefix) {
    if (prefix == "0") {
        return 0;
    }
    unsigned int result = 0xFFFFFFFF;
    result = result << (32 - atoi(prefix.c_str()));
    return result;
}

unsigned int prefix_to_available_ips(string prefix) {
    unsigned int result = 0xFFFFFFFF;
    result = result >> atoi(prefix.c_str());
    return result;
}

string prefix_to_netmask(string prefix) {
    return int_to_ipv4(prefix_to_int(prefix));
}


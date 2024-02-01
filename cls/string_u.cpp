//
#include "string_u.h"
#include <pcrecpp.h>

using std::stringstream;
using pcrecpp::RE;
using std::time_t;
using std::string;

bool isIpv4(const string& target) {
    RE oPattern("^([1-9]|[1-9]\\d|1\\d{2}|2[0-1]\\d|22[0-3])((\\.(\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])){3})$");
    return oPattern.FullMatch(target);
}

bool isPort(const int& port) {
    return(port >= 0 && port < 65536);
}

string bool_to_str(bool b) {
    string s;
    b ? s = "true" : s = "false";
    return s;
}

bool str_to_bool(const string& str) {
    if (str == "true")
        return true;
    if (str == "false")
        return false;
    return false;
}

string& strReplace(string& strBig, const string& strsrc, const string& strdst) {
    string::size_type pos = 0;
    string::size_type srclen = strsrc.size();
    string::size_type dstlen = strdst.size();
    while ((pos = strBig.find(strsrc, pos)) != string::npos) {
        strBig.replace(pos, srclen, strdst);
        pos += dstlen;
    }
    return strBig;
}
/*
int strSplit(const string& str, vector<string>& v, const char* p) {
    // char *tmp_str = NULL;
    auto tmp_str = (char*)malloc(str.size() + 1);
    memset(tmp_str, 0, str.size() + 1);
    memcpy(tmp_str, str.c_str(), str.size() + 1);
    v.clear();
    char* savePtr;
    char* pTmp = strtok_r(tmp_str, p, &savePtr);
    while(NULL != pTmp) {
        string tempStr = pTmp;
        v.push_back(tempStr);
        pTmp = strtok_r(NULL, p, &savePtr);
    }
    free(tmp_str);
    return v.size();
}
*/
int strSplit(const string& str, vector<string>& v, const char* p) {
    auto tmp_str = (char*)malloc(str.size() + 1);
    memset(tmp_str, 0, str.size() + 1);
    memcpy(tmp_str, str.c_str(), str.size() + 1);
    v.clear();
    char* savePtr;
    char* pTmp = strtok_r(tmp_str, p, &savePtr);
    while (NULL != pTmp) {
        string tempStr = pTmp;
        v.push_back(tempStr);
        pTmp = strtok_r(NULL, p, &savePtr);
    }
    free(tmp_str);
    return v.size();
}

string covertTime(long duration) {
    time_t tt;
    tt = duration;
    char now[64];
    strftime(now, 64, "%Y-%m-%d %H:%M:%S", localtime(&tt));
    return now;
}

time_t covertTime(string str) {
    tm tm_;
    char* cha = (char*)str.data();
    int year, month, day, hour, minute, second;
    sscanf(cha, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
    tm_.tm_year = year - 1900;
    tm_.tm_mon = month - 1;
    tm_.tm_mday = day;
    tm_.tm_hour = hour;
    tm_.tm_min = minute;
    tm_.tm_sec = second;
    tm_.tm_isdst = 0;

    time_t t_ = mktime(&tm_);
    return t_;
}

void int_to_bytes(int32_t i, char *bytes) {
    memset(bytes, '\0', 4);
    bytes[3] = 0xff & i;
    bytes[2] = 0xff & i >> 8;
    bytes[1] = 0xff & i >> 16;
    bytes[0] = 0xff & i >> 24;
}

int32_t bytes_to_int(char *bytes) {
    int32_t i = 0;
    i += ((unsigned char) bytes[0] << 24);
    i += ((unsigned char) bytes[1] << 16);
    i += ((unsigned char) bytes[2] << 8);
    i += (unsigned char) bytes[3];

    return i;
}

string& replace_all(string& str, const string& old_value, const string& new_value) {
    for (string::size_type pos(0); pos != string::npos; pos += new_value.length()) {
        if ((pos = str.find(old_value, pos)) != string::npos)
            str.replace(pos, old_value.length(), new_value);
        else
            break;
    }
    return str;
}

bool equals(const string& str1, const string& str2) {
    bool b;
    str1 == str2 ? b = true : b = false;
    return b;
}

string uuidGenerate() {
    string uuidStr;
    uuid_t uu;
    uuid_generate(uu);
    char out[37];
    uuid_unparse(uu, out);
    uuidStr.append(out);
    return uuidStr;
}

Json::Value str_to_json(const string& str) {
    Json::Value value;
    string err;
    Json::CharReaderBuilder reader;
    std::unique_ptr<Json::CharReader> const json_read(reader.newCharReader());
    json_read->parse(str.c_str(), str.c_str() + str.length(), &value, &err);
    return value;
}


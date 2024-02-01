#include <iostream>
#include <string.h>
#include <time.h>
#include <curl/curl.h>
#include "json/json.h"
#include <sys/time.h>

using namespace std;

size_t req_reply(void *ptr, size_t size, size_t nmemb, void *stream)
{
    std::string *str = (std::string *)stream;
    (*str).append((char *)ptr, size * nmemb);

    return size * nmemb;
}

CURLcode curl_post_req(const std::string &url, const std::string &postParams, std::string &response)
{

    CURL *curl = curl_easy_init();
    CURLcode res;

    if (curl != 0)
    {
        struct curl_slist *header_list = NULL;
        header_list = curl_slist_append(header_list, "User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64; Trident/7.0; rv:11.0) like Gecko");
        header_list = curl_slist_append(header_list, "Content-Type:application/json; charset=UTF-8");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_list);

        curl_easy_setopt(curl, CURLOPT_HEADER, 0);
        curl_easy_setopt(curl, CURLOPT_POST, 1);

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postParams.c_str());

        // ssl
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
        // CURLOPT_VERBOSE的值为1时，会显示详细的调试信息
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, req_reply);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);

        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);

        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

        res = curl_easy_perform(curl);
    }

    curl_easy_cleanup(curl);
    return res;
}

std::string time_to_str()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);

    long ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return to_string(ms);
}

void test_curl_post_req()
{
    std::string URLStr = "http://internal.oss.7x-networks.net/matrix/oauth/token?"; // 设置URL

    string strjson;

    strjson = "client_id=browser&";
    strjson += "client_secret=b7n3i7kzg22y3p035rw3rd9sfzvs4cv0&";
    strjson += "grant_type=password&";
    strjson += "password=0671313d02169fd0aff7a9d32551b83d&";
    strjson += "username=matrix";

    Json::FastWriter wrInfo;
    Json::Value wrValue;

    std::string paramsLogin = wrInfo.write(wrValue); // 设置post的json数据
    std::string resCode;                             // 返回值

    // URL封装
    std::string postStrURL = URLStr + strjson;

    auto res = curl_post_req(postStrURL, paramsLogin, resCode);
    if (res != CURLE_OK)
    {
        cout << "failed:  curl post error" << endl;
        return;
    }

    Json::Reader reader;
    Json::Value value;

    if (!reader.parse(resCode, value))
    {
        cout << "json parse error" << endl;
        return;
    }

    //cout << value.toStyledString() << endl;
    //Json::FastWriter writer;
    //cout << writer.write(value) << endl;

    std::string access_token = value["access_token"].asString();
    std::string refresh_token = value["refresh_token"].asString();
    std::string unix_time = time_to_str();

    cout << "unix_time: " << unix_time << endl;
    cout << "access_token: " << access_token << endl;
    cout << "refresh_token: " << refresh_token << endl;

    return;
}

int main()
{
    test_curl_post_req();

    return 0;
}

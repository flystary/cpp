#include <iostream>
#include <curl/curl.h>
#include <string.h>


using namespace std;

size_t req_reply(void *ptr, size_t size, size_t nmemb, void *stream)
{
    std::string *str = (std::string*)stream;
    (*str).append((char*)ptr, size*nmemb);

    return size * nmemb;
}


CURLcode curl_get_req(const std::string &url, std::string &response)
{
    CURL *curl = curl_easy_init();
    CURLcode res;

    if (curl) {
        struct curl_slist* header_list = NULL;
        header_list = curl_slist_append(header_list, "Content-Type:application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header_list);

        curl_easy_setopt(curl, CURLOPT_HEADER, 0);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);

        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, req_reply);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);

        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);

        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 6);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 6);

        res = curl_easy_perform(curl);
    }

    curl_easy_cleanup(curl);
    return res;
}


int test_curl_get_req()
{
    std::string URLStr = "http://www.baidu.com/";
    std::string getResponseStr;
    auto res = curl_get_req(URLStr, getResponseStr);
    if (res == CURLE_OK)
    {
        cout << getResponseStr << endl;
    }

    getchar();
    return 0;
}


int main()
{
    test_curl_get_req();

    return 0;
}

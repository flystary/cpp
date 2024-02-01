#include <stdio.h>
#include <iostream>
#include <curl/curl.h>

using namespace std;


size_t write_data(void* buffer, size_t size, size_t nmemb, void *stream) {
    printf("%s", buffer);
    return size*nmemb;
}

int main() {
    CURL *curl = curl_easy_init();
    CURLcode res;
    const char URL[] = "https://www.baidu.com";
    const char Parameter[] = "password=123";
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_POST, 1);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, Parameter);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
        curl_easy_setopt(curl, CURLOPT_HEADER, 1);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, true);
        curl_easy_setopt(curl, CURLOPT_FORBID_REUSE, 1);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
        curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "curlposttest.txt");
        curl_easy_setopt(curl, CURLOPT_COOKIEJAR, "curlposttest.txt");
        curl_easy_setopt(curl, CURLOPT_USERAGENT,"libcurl-agent/1.0");
        
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    getchar();

    return 0;
}

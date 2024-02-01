#include <curl/curl.h>

void testCurlFunc() {
    CURL* curl = 0;
    CURLcode res;
    curl = curl_easy_init();

    if (curl != 0) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://cip.cc");
        // curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
}


int main() {
    testCurlFunc();

    return 0;
}

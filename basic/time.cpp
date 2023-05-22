#include <iostream>
#include <ctime>

using namespace std;

int time_1()
{
    time_t now = time(0);
    char* dt = ctime(&now);

    cout << "date: " << dt << endl;

    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "UTC date: " << dt << endl;

    return 0;
}

int time_2()
{
    time_t now = time(0);
    cout << "Unix: " << now << endl;

    tm *ltm = localtime(&now);
    cout << 1900 + ltm->tm_year << "/";
    cout << 1 + ltm->tm_mon <<  "/";
    cout << ltm->tm_mday << "/ ";

    cout << ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;

    return 0;
}

int main()
{
    time_1();
    time_2();

    return 0;
}

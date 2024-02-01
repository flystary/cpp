#include<chrono>
#include<unistd.h>
#include<iostream>

using namespace std;


#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif //_WIN32

void sleep(int milliseconds)
{
    #ifdef __WIN32
        Sleep(milliseconds);
    #else
        usleep(milliseconds * 1000);
    #endif
}

class Timer {
public:
    Timer() : m_StartTimepoint(std::chrono::high_resolution_clock::now()) {}

    ~Timer() {
        Stop();
    }

    void Stop() {
        auto endTimepoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::nanoseconds>(m_StartTimepoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::nanoseconds>(endTimepoint).time_since_epoch().count();

        auto duration = end - start;
        double ms = duration * 1e-6;

        std::cout << duration << "ns (" << ms << "ms)\n";
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
};


int main() {
    {
        Timer timer;
        for(int i = 0; i < 100000; i++);
        sleep(1);
    }
    return 0;
}

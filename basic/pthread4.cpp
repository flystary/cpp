#include <iostream>
#include <thread>

std::thread::id main_thread_id = std::this_thread::get_id();

using namespace std;


void hello()
{
    cout << "Hello World\n" <<endl;
    if (main_thread_id == std::this_thread::get_id())
        cout << "This is main thread.\n";
    else
        cout << "This is not the main thread.\n";
}

void pause_thread(int n) {
    std::this_thread::sleep_for(std::chrono::seconds(n));
    cout << "pause of " << n << "seconds ended\n";
}

int threa()
{
    std::thread t(hello);
    std::cout << t.hardware_concurrency() << std::endl;//可以并发执行多少个(不准确)
    std::cout << "native_handle " << t.native_handle() << std::endl;//可以并发执行多少个(不准确)
    t.join();
    std::thread a(hello);
    a.detach();
    std::thread threads[5];                         // 默认构造线程

    std::cout << "Spawning 5 threads...\n";

    for(int i = 0; i < 5; ++i)
        threads[i] = std::thread(pause_thread, i + 1);
    cout << "Done spawning threads.\n";

    for (auto &thread : threads)
        thread.join();
    cout << "All thread joined!\n";
}


int main()
{
    threa();

    return 0;
}

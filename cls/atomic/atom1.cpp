#include <iostream>
#include <thread>
#include <atomic>

using namespace std;
std::atomic<int> g_count(0); //封装了一个类型为int的 对象（值）

void mythread1() {
    for (int i = 0; i < 1000000; i++) {
        g_count++;
    }
}
 
int main() {
    std::thread t1(mythread1);
    std::thread t2(mythread1);
    t1.join();
    t2.join();
    cout << "正常情况下结果应该是200 0000次，实际是" << g_count << endl;
}

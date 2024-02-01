#include <iostream>  
#include <thread>  
#include <vector>  
#include <atomic>  
  
std::atomic<int> counter(0); // 定义一个原子整数计数器  
  
void increment() {  
    for (int i = 0; i < 1000; ++i) {  
        ++counter; // 原子增加操作  
    }  
}  
  
int main() {  
    std::vector<std::thread> threads;  
    for (int i = 0; i < 10; ++i) {  
        threads.push_back(std::thread(increment)); // 创建多个线程同时增加计数器  
    }  
  
    for (auto& t : threads) {  
        t.join(); // 等待所有线程执行完毕  
    }  
  
    std::cout << "Counter: " << counter << std::endl; // 输出最终的计数器值  
    return 0;  
}

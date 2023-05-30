#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void foo(int Z)
{
    for (int i = 0; i < Z; i++) {
        sleep(1);
        cout << "线程使用函数指针\n";
    }
}


class thread_obj {
public:
    void operator() (int x)
    {
        for(int i = 0; i < x; i++)
            cout << "线程使用函数对象\n";
    }
};

int threa()
{
    cout << "线程 1 2 3 "
            "独立运行" << endl;

    thread th1(foo, 3);
    thread th2(thread_obj(), 3);

    auto f = [](int x) {
        for (int i = 0; i < x; i++)
            cout << "线程使用lambda表达式i\n";
    };

    thread th3(f, 3);
    th1.join();
    th2.join();
    th3.join();

    return 0;
}


int main()
{
    threa();

    return 0;
}

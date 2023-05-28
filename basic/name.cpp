#include <iostream>
using namespace std;

namespace first_space {
    void func() {
        cout << "Inside first_space" << endl;
    }
}

namespace second_space {
    void func() {
        cout << "Inside secod_space" << endl;
    }
}
int name()
{
    first_space::func();
    second_space::func();
    return 0;
}

using namespace first_space;
int name_1()
{
    func();
    return 0;
}

namespace first{
    void func_1() {
        cout << "First" << endl;
    }
    namespace second {
        void func_1() {
            cout << "Second" << endl;
        }
    }
}

using namespace first::second;
int name_2()
{
    func_1();
}

int main()
{
    name();
    name_1();

    cout << endl;
    name_2();
    return 0;
}

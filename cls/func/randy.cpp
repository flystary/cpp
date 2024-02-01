#include <iostream>

using namespace std;

class Randy {
public:
    void R1_Non_Static() {
        cout << "call -> R1_Non_Static" << endl;
    }

    static void R2_Static() {
        cout << "call -> R2_Static" << endl;
    }

    static void Wrapper(void *objectR) {
        cout << "call -> Wrapper" << endl;
        reinterpret_cast<Randy *>(objectR)->R1_Non_Static();
    }
};

class Sesame {
public:
    void Ses_call1(void (*callBack)()) {
        cout << "call -> Ses_call1" << endl;
        callBack();
    }

    void Ses_call2(void (Randy::*callBack)(), void *object) {
        cout << "call -> Ses_call2" << endl;
        ((Randy *)object->*callBack)();
    }

    void Ses_call3(void (*callBack)(void *), void *objactS) {
        cout << "call -> Ses_call3" << endl;
        callBack(objactS);
    }
};

int main(int argc, char **argv) {
    Randy  randy;
    Sesame sesame;

    sesame.Ses_call2(&Randy::R1_Non_Static, &randy);
    sesame.Ses_call1(Randy::R2_Static);
    sesame.Ses_call3(&Randy::Wrapper, &randy);

    return 0;
}


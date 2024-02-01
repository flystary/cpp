#include <iostream>

class Randy {
public:
    void R1_Non_Static() {
        std::cout << "call function R1" << std::endl;
    }
    static void R2_Static() {
        std::cout << "call function R2" << std::endl;
    }
};

class Sesame {
public:
    void Ses_call1(void (*callBack)()) {
        std::cout << "call function Ses_call1" << std::endl;
        callBack();
    }

    void Ses_call2(void (Randy::*callBack)(), void *object) {
        std::cout << "call function Ses_call2" << std::endl;
        ((Randy *)object->*callBack)();
    }
};

int main(int argc, char **argv) {
    Randy  randy;
    Sesame sesame;

    sesame.Ses_call2(&Randy::R1_Non_Static, &randy);
    sesame.Ses_call1(Randy::R2_Static);
}

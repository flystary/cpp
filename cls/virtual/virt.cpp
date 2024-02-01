#include <iostream>

struct Base {
    virtual void display(int i = 5) { std::cout << "Base:: " << i << "\n"; }
};


struct Derived : public Base {
    virtual void display(int i = 9) override  {std::cout << "Derived:: " << i << "\n"; }
};

int main()
{
    Base* a  = new Derived();
    a->display();

    Base* aa = new Base();
    aa->display();
    

    Derived* b = new Derived();
    b->display(); 

    return 0;
}



#include <iostream>

using namespace std;

class Box
{
    double width;
public:
    friend void printWidth(Box box);
    void setWidth(double wid);
};

void Box::setWidth(double wid)
{
    width = wid;
}

void printWidth(Box box)
{
    cout << "Width of box: " << box.width << endl;
}

int class_1()
{
    Box box;
    
    box.setWidth(19.0);

    printWidth(box);

    return 0;
}

int main()
{
    class_1();

    return 0;
}


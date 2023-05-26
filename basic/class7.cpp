#include <iostream>

using namespace std;

class Box
{
    public:
        Box(double l=2.0, double b=2.0, double h=2.0)
        {
            cout << "Constructor called." << endl;
            length  = l;
            breadth = b;
            heigth  = h; 
        }
        double Volume()
        {
            return length * breadth * heigth;
        }
        int compare(Box box)
        {
            return this->Volume() > box.Volume();
        }

    private:
        double length;
        double breadth;
        double heigth;
};

int class_()
{
    Box Box1(3.3, 1.2, 1.5);
    Box Box2(8.5, 6.0, 2.0);

    if(Box1.compare(Box2))
    {
        cout << "Box2 < Box1" << endl;
    }
    else
    {
        cout << "Box2 == & > Box1" << endl;
    }

    return 0;
}


int main()
{
    class_();

    return 0;
}

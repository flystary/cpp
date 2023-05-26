#include <iostream>

using namespace std;

class Box
{
    public:
        static int objectCount;
        Box(double l=2.0, double b=2.0, double h=2.0)
        {
            cout << "Constructor called." << endl;

            length  = l;
            breadth = b;
            height  = h;

            objectCount++;
        }

        double Volume()
        {
            return length * breadth * height;
        }

    private:
        double length;
        double breadth;
        double height;
};

int Box::objectCount = 0;


/*
 * 静态成员函数没有 this 指针，只能访问静态成员（包括静态成员变量和静态成员函数）。
 * 普通成员函数有 this 指针，可以访问类中的任意成员；而静态成员函数没有 this 指针。
 */

int class_1(void)
{
    Box     Box1(3.3, 1.2, 1.5);
    Box     Box2(8.5, 6.0, 2.0);
    Box     Box3(7.5, 5.0, 2.0);
    Box     Box4(6.5, 4.0, 3.0);
    Box     Box5(5.5, 3.0, 4.0);

    cout << "Total objects: " << Box::objectCount << endl;

    return 0;
}

class Cpe
{
    public:
        static  int objectCount;
        Cpe(double l=2.0, double b=2.0, double h=2.0)
        {
            cout << "Constructor called." << endl;
            length  = l;
            breadth = b;
            height  = h;
            
            objectCount++;
        }
        double Volume()
        {
            return length * breadth * height;
        }

        static int getCount()
        {
            return objectCount;
        }
    private:
        double length;
        double breadth;
        double height;
};

int Cpe::objectCount = 0;

int class_2()
{
    cout << "Inital Stage Count: " << Cpe::getCount() << endl;
 
    Cpe Cpe1(3.3, 1.2, 1.5); 
    Cpe Cpe2(8.5, 6.0, 2.0);

    cout << "Final Stage Count: " <<Cpe::getCount() << endl;

}

int main()
{
    class_1();

    cout << "\n";
    class_2();
}

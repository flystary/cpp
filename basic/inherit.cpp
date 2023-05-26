#include <iostream>

using namespace std;


class Shape
{
    public:
        void setWidth(int w)
        {
            width = w;
        }

        void setHeight(int h)
        {
            height = h;
        }
   
    protected:
        int     width;
        int     height;
};


class Rectangle: public Shape
{
    public:
        int getArea()
        {
            return (width * height);
        }
};

int inh_1()
{
    Rectangle Rect;
    Rect.setWidth(5);
    Rect.setHeight(10);
    
    cout << "Total area: " << Rect.getArea() << endl;

    return 0;
}

int main()
{
    inh_1();

    return 0;
}

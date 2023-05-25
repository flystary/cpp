#include <iostream>

using namespace std;

class Line
{
    public:
        int  getLength(void);
        Line( int len);
        Line( const Line &obj);
        ~Line();

    private:
        int *ptr;
};


Line::Line(int len)
{
    cout << "调用构造函数" << endl;
    ptr = new int;
    *ptr = len;
}


Line::Line(const Line &obj)
{
    cout << "分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr;
}

Line::~Line(void)
{
    cout << "释放内存" << endl;
    delete ptr;
}

int Line::getLength(void)
{
    return *ptr;    
}

void display(Line obj)
{
    cout << "line size: " << obj.getLength() << endl;
}

int class_1()
{
    Line line(10);

    display(line);

    return 0;
}

int class_2()
{
    Line line1(15);
    Line line2 = line1;

    display(line1);
    display(line2);

    return 0;
}

int main()
{
    class_1();
    cout << "\n";
    class_2();

    return 0;
}

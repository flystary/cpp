#include <iostream>

using namespace std;

class Box
{
    public:
        double length;
        double breadth;
        double height;
        double get(void);
        void set(double len, double bre, double hei);
};

double Box::get(void)
{
    return length * breadth * height;
}

void Box::set(double len, double bre, double hei)
{
    length  = len;
    breadth = bre;
    height  = hei;
}

int class_1()
{
    Box     Box1;
    Box     Box2;
    Box     Box3;

    double volume = 0.0;

    Box1.height = 5.0; 
    Box1.length = 6.0; 
    Box1.breadth = 7.0;

    Box2.height = 10.0; 
    Box2.length = 12.0; 
    Box2.breadth = 13.0;

    volume = Box1.height * Box1.length * Box1.breadth;
    cout << "Box1 的体积：" << volume <<endl;

    volume = Box2.height * Box2.length * Box2.breadth;
    cout << "Box2 的体积：" << volume <<endl;

    Box3.set(16.0, 8.0, 12.0);
    volume = Box3.get();
    cout << "Box3 的体积：" << volume <<endl;

    return 0;

}

class Cpe
{
    public:
        double length;
        double breadth;
        double height;

        double getVolume(void)
        {
            return length * breadth * height;
        }

        void setLength(double len)
        {
            length = len;
        }

        void setBreadth(double bre)
        {
            breadth = bre;
        }

        void setHeight(double hei)
        {
            height = hei;
        }
        
        double getBArea(void);
        double getLArea(void);
};

double Cpe::getBArea(void) 
{
    return length * breadth;
}
double Cpe::getLArea(void) 
{
    return length * height;
}


int class_2()
{
    Cpe Cpe1;
    Cpe Cpe2;
    double volume = 0.0;
    double LArea  = 0.0;
    double BArea  = 0.0;

    Cpe1.setLength(6.0); 
    Cpe1.setBreadth(7.0); 
    Cpe1.setHeight(5.0);

    Cpe2.setLength(6.0); 
    Cpe2.setBreadth(7.0); 
    Cpe2.setHeight(5.0);


    volume = Cpe1.getVolume();
    BArea  = Cpe1.getBArea();
    LArea  = Cpe1.getLArea();
    cout << "Cpe1 的体积：" << volume <<endl;
    cout << "Cpe1 的底面积：" << BArea <<endl;
    cout << "Cpe1 的侧面积：" << LArea <<endl;

    volume = Cpe2.getVolume();
    BArea  = Cpe2.getBArea();
    LArea  = Cpe2.getLArea();
    cout << "Cpe2 的体积：" << volume <<endl;
    cout << "Cpe2 的底面积：" << BArea <<endl;
    cout << "Cpe2 的侧面积：" << LArea <<endl;

    return 0;
}



class Box1
{
   public:
      double length;
      void setWidth( double wid );
      double getWidth( void );
 
   private:
      double width;
};
 
// 成员函数定义
double Box1::getWidth(void)
{
    return width ;
}
 
void Box1::setWidth( double wid )
{
    width = wid;
}
 
// 程序的主函数
int class_3( )
{
   Box1 box;
 
   // 不使用成员函数设置长度
   box.length = 10.0; // OK: 因为 length 是公有的
   cout << "Length of box : " << box.length <<endl;
 
   // 不使用成员函数设置宽度
   // box.width = 10.0; // Error: 因为 width 是私有的
   box.setWidth(10.0);  // 使用成员函数设置宽度
   cout << "Width of box : " << box.getWidth() <<endl;
 
   return 0;
}



class Box2
{
   protected:
      double width;
};
 
class SmallBox:Box2 // SmallBox 是派生类
{
   public:
      void setSmallWidth( double wid );
      double getSmallWidth( void );
};
 
// 子类的成员函数
double SmallBox::getSmallWidth(void)
{
    return width ;
}
 
void SmallBox::setSmallWidth( double wid )
{
    width = wid;
}
 
// 程序的主函数
int class_4( )
{
   SmallBox box;
 
   // 使用成员函数设置宽度
   box.setSmallWidth(5.0);
   cout << "Width of box : "<< box.getSmallWidth() << endl;
 
   return 0;
}

int main()
{
    class_1();
    cout << "\n";

    class_2();
    cout << "\n";

    class_3();
    cout << "\n";

    class_4();
    return 0;
}

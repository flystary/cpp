#include <iostream>

using namespace std;

class A {
public:
    int a;

    A() {
       a1 = 1;
       a2 = 2;
       a3 = 3;
       a  = 4;
    }

    void func() {
        cout << a << endl;
        cout << a1 << endl;
        cout << a2 << endl;
        cout << a3 << endl;
    }

public:
    int a1;
protected:
    int a2;
private:
    int a3;
};

class B : public A {
public:
  int a;
  B(int i){
    A();
    a = i;
  }
  void fun(){
    cout << a << endl;       //正确，public成员
    cout << a1 << endl;       //正确，基类的public成员，在派生类中仍是public成员。
    cout << a2 << endl;       //正确，基类的protected成员，在派生类中仍是protected可以被派生类访问。
    // cout << a3 << endl;       //错误，基类的private成员不能被派生类访问。
  }
};

int class_A(){
  B b(10);
  cout << b.a << endl;
  cout << b.a1 << endl;   //正确
  // cout << b.a2 << endl;   //错误，类外不能访问protected成员
  // cout << b.a3 << endl;   //错误，类外不能访问private成员
  // system("pause");
  return 0;
}


///////////////////////////////////////////////////////////
class C {
public:
  int a;
  C(){
    a1 = 1;
    a2 = 2;
    a3 = 3;
    a = 4;
  }
  void fun(){
    cout << a << endl;    //正确
    cout << a1 << endl;   //正确
    cout << a2 << endl;   //正确
    cout << a3 << endl;   //正确
  }
public:
  int a1;
protected:
  int a2;
private:
  int a3;
};
class D : protected C{
public:
  int a;
  D(int i){
    C();
    a = i;
  }
  void fun(){
    cout << a << endl;       //正确，public成员。
    cout << a1 << endl;       //正确，基类的public成员，在派生类中变成了protected，可以被派生类访问。
    cout << a2 << endl;       //正确，基类的protected成员，在派生类中还是protected，可以被派生类访问。
    // cout << a3 << endl;       //错误，基类的private成员不能被派生类访问。
  }
};
int class_C(){
  D d(10);
  cout << d.a << endl;       //正确。public成员
 // cout << d.a1 << endl;      //错误，protected成员不能在类外访问。
 // cout << d.a2 << endl;      //错误，protected成员不能在类外访问。
 // cout << d.a3 << endl;      //错误，private成员不能在类外访问。
 // system("pause");
  return 0;
}

/////////////////////////
class E{
public:
  int a;
  E(){
    a1 = 1;
    a2 = 2;
    a3 = 3;
    a = 4;
  }
  void fun(){
    cout << a << endl;    //正确
    cout << a1 << endl;   //正确
    cout << a2 << endl;   //正确
    cout << a3 << endl;   //正确
  }
public:
  int a1;
protected:
  int a2;
private:
  int a3;
};
class F : private A{
public:
  int a;
  F(int i){
    E();
    a = i;
  }
  void fun(){
    cout << a << endl;       //正确，public成员。
    cout << a1 << endl;       //正确，基类public成员,在派生类中变成了private,可以被派生类访问。
    cout << a2 << endl;       //正确，基类的protected成员，在派生类中变成了private,可以被派生类访问。
   //  cout << a3 << endl;       //错误，基类的private成员不能被派生类访问。
  }
};
int class_E(){
  F f(10);
  cout << f.a << endl;       //正确。public成员
  // cout << f.a1 << endl;      //错误，private成员不能在类外访问。
  // cout << f.a2 << endl;      //错误, private成员不能在类外访问。
  // cout << f.a3 << endl;      //错误，private成员不能在类外访问。
  // system("pause");
  return 0;
}

int main()
{
    class_A();
    class_C();
    class_E();

    return 0;
}

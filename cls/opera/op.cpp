#include <iostream>


using namespace std;

class A
{
public:
    A(double _data = 0.0):data(_data) {}
    A& operator = (const A& rhs)
    {
        data = rhs.data;
        return *this;
    }

    friend A operator + (const A& lhs, const A& rhs);
    friend A operator - (const A& lhs, const A& rhs);
    friend A operator * (const A& lhs, const A& rhs);

    friend A operator + (const A& lhs, double rhs);
    friend A operator + (double lhs, const A& rhs);
    friend A operator * (const A& lhs, double rhs);
    friend A operator * (double lhs, const A& rhs);
    friend A operator - (const A& lhs, double rhs);
    friend A operator - (double lhs, const A& rhs);

    friend ostream& operator << (ostream& fout, A& a);

private:
    double data;
};

A operator + (const A& lhs,const A& rhs)
{
    A res(0);
    res.data = lhs.data + rhs.data;
    return res;
}

A operator - (const A& lhs,const A& rhs)
{
    A res(0);
    res.data = lhs.data - rhs.data;
    return res;
}

A operator * (const A& lhs,const A& rhs)
{
    A res(0);
    res.data = lhs.data * rhs.data;
    return res;
}

A operator + (const A& lhs,double rhs)
{
    A res(0);
    res.data = lhs.data + rhs;
    return res;
}
 
A operator + (double lhs,const A& rhs)
{
    A res(0);
    res.data = lhs + rhs.data;
    return res;
}

A operator * (const A& lhs,double rhs)
{
    A res(0);
    res.data = lhs.data * rhs;
    return res;
}

A operator * (double lhs,const A& rhs)
{
    A res(0);
    res.data = lhs * rhs.data;
    return res;
}

A operator - (const A& lhs,double rhs)
{
    A res(0);
    res.data = lhs.data - rhs;
    return res; 
}

A operator - (double lhs,const A& rhs)
{
    A res(0);
    res.data = lhs - rhs.data;
    return res; 
}
     
ostream& operator << (ostream& fout,A& a)
{
    fout << a.data ;
    return fout;
}

int main(int argc, char* argv[])
{
    A a(2.3);
    A b(1.2);
    A d(3.4);

    A c;
    c = a + b + d;
    cout << c << endl;
    c = a + b;
    cout << c << endl;
    c = a + 1.0;
    cout << c << endl;
    c = a - b;
    cout << c << endl;
    c = a - 1.0;
    cout << c << endl;
    c = a * b;
    cout << c << endl;
    c = a * 1.0;
    cout << c << endl;
    
    c=1.0+2.0*a*a-3.0*a*b;
    cout << c << endl;
    return 0;

}

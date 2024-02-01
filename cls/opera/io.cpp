#include<iostream>
using namespace std;

class rectangle {
private:
    int length, width;
public:
    rectangle(int l, int w){
        length = l;
        width  = w;
    }
    friend istream &operator>>(istream &in, rectangle &a);
    friend ostream &operator<<(ostream &os, rectangle &a);
};

istream &operator>>(istream &in, rectangle &a){
    in >> a.length >> a.width;
    return in;
}

ostream &operator<<(ostream &os, rectangle &a){
    os << a.length << endl << a.width << endl;
    return os;
}

int main(){
    rectangle A(5,5);
    rectangle B(5,5);

    cin >> A;
    cout << A;
    cout << B;

    return 0;
};

#include <fstream>
#include <iostream>

class Person
{
    public:
        char Name[64];
        int Age;
};


int main()
{
    ofstream ofs;
    ofs.open("test.txt", ios::out | ios::binary);

    Person p("张三, 18");
    ofs.write((const char *)&p, sizeof(Person));
    ofs.close();
}

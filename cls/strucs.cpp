#include <iostream>
#include <string>

using namespace std;

struct Person
{
    Person(std::string name);
    std::string greet(std::string other_name);
    std::string my_name;
};


Person::Person(std::string name)
{
    my_name = name;
}

std::string Person::greet(std::string other_name)
{
    return "Hi " + other_name + ", My name is " + my_name;
}

int main()
{
    Person my_person("JANE");
    std::string str = my_person.greet("JOE");
    std::cout << str << std::endl;
}

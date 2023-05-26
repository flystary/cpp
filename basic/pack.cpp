#include <iostream>

using namespace std;

class Adder {
    public:
        Adder(int i=0):total(i) { };
    
        void addNum(int num)
        {
            total += num;
        }
        int getTotal()
        {
            return total;
        }

    private:
        int total;
};

int pack()
{
    Adder a;
    
    a.addNum(1);
    a.addNum(2);
    a.addNum(5);
    a.addNum(10);

    cout << "Total: " << a.getTotal() << endl;
    return 0;
}

int main()
{
    pack();

    return 0;
}

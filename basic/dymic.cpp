#include <iostream>

using namespace std;

int dym()
{
    double* pvalue = NULL;

    pvalue = new double;

    *pvalue = 29494.99;
    cout << "Value of pvalue: " << *pvalue << endl;
    delete pvalue;

    return 0;
}

int dym_1()
{
    int *array = new int [m];

    delete [] array;

    return 0;
}

int dym_2()
{
    int **array;

    array = new int *[m];

    for (int i = 0; i < m; i++)
    {
        array[i] = new int [n];
    }

    cout << array << endl;

    for (int i = 0; i < m; i++)
    {
        delete [] array[i];
    }

    delete []array;

    return 0;
}



int main()
{
    dym();

    return 0;
}

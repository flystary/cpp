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
/*
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
*/
int dym_3()
{
    int **p;
    int i, j;
    
    p = new int *[4];
    for(i=0;i<4;i++){
        p[i] = new int [8];
    }

    for(i=0;i<4;i++){
        for(j=0;j<8;j++){
            p[i][j] = j*i;
        }
    }

    for(i=0;i<4;i++) {
        for(j=0;j<8;j++)
        {
            if(j==0) cout << endl;
            cout << p[i][j] << "\t";
        }
    }
    cout << endl;

    for(i=0; i < 4; i++)
    {
        delete [] p[i];
    }
    delete [] p;
    return 0;
}

int dym_4()
{   
    int i,j,k;   // p[2][3][4]
    
    int ***p;
    p = new int **[2]; 
    for(i=0; i<2; i++) 
    { 
        p[i]=new int *[3]; 
        for(j=0; j<3; j++) 
            p[i][j]=new int[4]; 
    }
    
    //输出 p[i][j][k] 三维数据
    for(i=0; i<2; i++)   
    {
        for(j=0; j<3; j++)   
        { 
            for(k=0;k<4;k++)
            { 
                p[i][j][k]=i+j+k;
                cout<<p[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    
    // 释放内存
    for(i=0; i<2; i++) 
    {
        for(j=0; j<3; j++) 
        {   
            delete [] p[i][j];   
        }   
    }       
    for(i=0; i<2; i++)   
    {       
        delete [] p[i];   
    }   
    delete [] p;  
    return 0;
}


class Box
{
    public:
        Box() {
            cout << "调用函数" << endl;
        }
        ~Box() {
            cout << "调用析构函数" << endl;
        }
};

int dym_5()
{
    Box* myBoxs = new Box[4];

    delete []myBoxs;

    return 0;
}
int main()
{
    // dym();
    dym_3();
    dym_4();
    dym_5();

    return 0;
}

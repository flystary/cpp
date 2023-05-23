#include <iostream>
#include <cstring>

using namespace std;

struct Books
{
    char  title[50];
    char  author[50];
    char  subject[100];
    int   book_id;
};

int struct_1()
{
    Books Book1;        // 定义结构体类型 Books 的变量 Book1
    Books Book2;        // 定义结构体类型 Books 的变量 Book2
 
    // Book1 详述
    strcpy( Book1.title, "C++ 教程");
    strcpy( Book1.author, "Runoob"); 
    strcpy( Book1.subject, "编程语言");
    Book1.book_id = 12345;
 
    // Book2 详述
    strcpy( Book2.title, "CSS 教程");
    strcpy( Book2.author, "Runoob");
    strcpy( Book2.subject, "前端技术");
    Book2.book_id = 12346;
 
    // 输出 Book1 信息
    cout << "第一本书标题 : " << Book1.title <<endl;
    cout << "第一本书作者 : " << Book1.author <<endl;
    cout << "第一本书类目 : " << Book1.subject <<endl;
    cout << "第一本书 ID : " << Book1.book_id <<endl;
 
    // 输出 Book2 信息
    cout << "第二本书标题 : " << Book2.title <<endl;
    cout << "第二本书作者 : " << Book2.author <<endl;
    cout << "第二本书类目 : " << Book2.subject <<endl;
    cout << "第二本书 ID : " << Book2.book_id <<endl;
 
    return 0;
} 

void printBook(struct Books book);

int struct_2()
{
    Books Book1;
    Books Book2;
 
    // Book1 详述
    strcpy( Book1.title, "C++ 教程");
    strcpy( Book1.author, "Runoob"); 
    strcpy( Book1.subject, "编程语言");
    Book1.book_id = 12345;
     
    // Book2 详述
    strcpy( Book2.title, "CSS 教程");
    strcpy( Book2.author, "Runoob");
    strcpy( Book2.subject, "前端技术");
    Book2.book_id = 12346;
    //                              
    // 输出 Book1 信息
    printBook( Book1 );
    //                                     
    // 输出 Book2 信息
    printBook( Book2 );   
    return 0;
}

void printBook(struct Books book)
{
    cout << "书标题 : " << book.title <<endl;
    cout << "书作者 : " << book.author <<endl;
    cout << "书类目 : " << book.subject <<endl;
    cout << "书 ID : " << book.book_id <<endl;
}

void printBook1(struct Books *book1);

int struct_3()
{
    Books Book1;        // 定义结构体类型 Books 的变量 Book1
    Books Book2;        // 定义结构体类型 Books 的变量 Book2
 
    // Book1 详述
    strcpy( Book1.title, "C++ 教程");
    strcpy( Book1.author, "Runoob"); 
    strcpy( Book1.subject, "编程语言");
    Book1.book_id = 12345;
 
    // Book2 详述
    strcpy( Book2.title, "CSS 教程");
    strcpy( Book2.author, "Runoob");
    strcpy( Book2.subject, "前端技术");
    Book2.book_id = 12346;
 
    // 通过传 Book1 的地址来输出 Book1 信息
    printBook1( &Book1 );
 
    // 通过传 Book2 的地址来输出 Book2 信息
    printBook1( &Book2 );
 
    return 0;
}

void printBook1(struct Books *book1)
{
    cout << "书标题  : " << book1->title <<endl;
    cout << "书作者 : " << book1->author <<endl;
    cout << "书类目 : " << book1->subject <<endl;
    cout << "书 ID : " << book1->book_id <<endl;
}

typedef struct tBooks
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
}tBooks;


int struct_4()
{
    sBooks Book1, Book2;
    
    typedef long int *pint32;
    pint32 x, y, z;
}

int main()
{
    struct_1();
    cout << "\n";

    struct_2();
    cout << "\n";

    struct_3();

    return 0;
}

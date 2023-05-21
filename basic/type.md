# 修饰符类型


### 数据类型修饰符
- signed：表示变量可以存储负数。对于整型变量来说，signed 可以省略，因为整型变量默认为有符号类型。
- unsigned：表示变量不能存储负数。对于整型变量来说，unsigned 可以将变量范围扩大一倍。
- short：表示变量的范围比 int 更小。short int 可以缩写为 short。
- long：表示变量的范围比 int 更大。long int 可以缩写为 long。
- long long：表示变量的范围比 long 更大。C++11 中新增的数据类型修饰符。
- float：表示单精度浮点数。
- double：表示双精度浮点数。
- bool：表示布尔类型，只有 true 和 false 两个值。
- char：表示字符类型。
- wchar_t：表示宽字符类型，可以存储 Unicode 字符。

### 类型限定符
- const   const 定义常量，表示该变量的值不能被修改。。
- volatile    修饰符 volatile 告诉该变量的值可能会被程序以外的因素改变，如硬件或其他线程。。
- restrict    由 restrict 修饰的指针是唯一一种访问它所指向的对象的方式。只有 C99 增加了新的类型限定符 restrict。
- mutable 表示类中的成员变量可以在 const 成员函数中被修改。
- static  用于定义静态变量，表示该变量的作用域仅限于当前文件或当前函数内，不会被其他文件或函数访问。
- register    用于定义寄存器变量，表示该变量被频繁使用，可以存储在CPU的寄存器中，以提高程序的运行效率。

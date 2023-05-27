## 异常处理
try catch throw

throw: 当问题出现时，程序会抛出一个异常。这是通过使用 throw 关键字来完成的。
catch: 在您想要处理问题的地方，通过异常处理程序捕获异常。catch 关键字用于捕获异常。
try: try 块中的代码标识将被激活的特定异常。它后面通常跟着一个或多个 catch 块。

```C++
try
{
   // 保护代码
}catch( ExceptionName e1 )
{
   // catch 块
}catch( ExceptionName e2 )
{
   // catch 块
}catch( ExceptionName eN )
{
   // catch 块
}
```


### 捕获异常
```C++
try
{
   // 保护代码
}catch( ExceptionName e )
{
  // 处理 ExceptionName 异常的代码
}
```

```C++
try
{
   // 保护代码
}catch(...)
{
  // 能处理任何异常的代码
}
```

异常    描述
std::exception  该异常是所有标准 C++ 异常的父类。
std::bad_alloc  该异常可以通过 new 抛出。
std::bad_cast   该异常可以通过 dynamic_cast 抛出。
std::bad_typeid 该异常可以通过 typeid 抛出。
std::bad_exception  这在处理 C++ 程序中无法预期的异常时非常有用。
std::logic_error    理论上可以通过读取代码来检测到的异常。
std::domain_error   当使用了一个无效的数学域时，会抛出该异常。
std::invalid_argument   当使用了无效的参数时，会抛出该异常。
std::length_error   当创建了太长的 std::string 时，会抛出该异常。
std::out_of_range   该异常可以通过方法抛出，例如 std::vector 和 std::bitset<>::operator[]()。
std::runtime_error  理论上不可以通过读取代码来检测到的异常。
std::overflow_error 当发生数学上溢时，会抛出该异常。
std::range_error    当尝试存储超出范围的值时，会抛出该异常。
std::underflow_error    当发生数学下溢时，会抛出该异常。

### 定义新的异常


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

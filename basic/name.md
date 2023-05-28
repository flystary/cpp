## 命名空间
```C++
namespace namespace_name {
   // 代码声明
}
```

```C++
name::code;  // code 可以是变量或函数
```

### 嵌套
```C++
namespace namespace_name1 {
   // 代码声明
   namespace namespace_name2 {
      // 代码声明
   }
}

// 访问 namespace_name2 中的成员
using namespace namespace_name1::namespace_name2;
 
// 访问 namespace_name1 中的成员
using namespace namespace_name1;
```

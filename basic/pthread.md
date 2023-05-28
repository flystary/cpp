## 多线程
多线程是多任务处理的一种特殊形式，多任务处理允许让电脑同时运行两个或两个以上的程序。一般情况下，两种类型的多任务处理：基于进程和基于线程。

基于进程的多任务处理是程序的并发执行。
基于线程的多任务处理是同一程序的片段的并发执行。

```C++
#include <pthread.h>
pthread_create (thread, attr, start_routine, arg) 
```

参数    描述
thread  指向线程标识符指针。
attr    一个不透明的属性对象，可以被用来设置线程属性。您可以指定线程属性对象，也可以使用默认值 NULL。
start_routine   线程运行函数起始地址，一旦线程被创建就会执行。
arg 运行函数的参数。它必须通过把引用作为指针强制转换为 void 类型进行传递。如果没有传递参数，则使用 NULL。

### 终止线程
```C++
#include <pthread.h>
pthread_exit (status) 
```



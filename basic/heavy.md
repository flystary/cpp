## 重载

### 可重载运算符
双目算术运算符  + (加)，-(减)，*(乘)，/(除)，% (取模)
关系运算符  ==(等于)，!= (不等于)，< (小于)，> (大于)，<=(小于等于)，>=(大于等于)
逻辑运算符  ||(逻辑或)，&&(逻辑与)，!(逻辑非)
单目运算符  + (正)，-(负)，*(指针)，&(取地址)
自增自减运算符  ++(自增)，--(自减)
位运算符    | (按位或)，& (按位与)，~(按位取反)，^(按位异或),，<< (左移)，>>(右移)
赋值运算符  =, +=, -=, *=, /= , % = , &=, |=, ^=, <<=, >>=
空间申请与释放  new, delete, new[ ] , delete[]
其他运算符  ()(函数调用)，->(成员访问)，,(逗号)，[](下标)

### 不可重载运算符

.：成员访问运算符
.*, ->*：成员指针访问运算符
::：域运算符
sizeof：长度运算符
?:：条件运算符
#： 预处理符号


序号    运算符和实例
1   一元运算符重载
2   二元运算符重载
3   关系运算符重载
4   输入/输出运算符重载
5   ++ 和 -- 运算符重载
6   赋值运算符重载
7   函数调用运算符 () 重载
8   下标运算符 [] 重载
9   类成员访问运算符 -> 重载

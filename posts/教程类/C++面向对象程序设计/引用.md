# 引用

语法结构`数据类型 &别名=原名`

注意事项：

- 引用必须在定义的时候必须要初始化。

- 引用在初始化后不允许更改引用。

引用做函数参数，进行引用传递：其和按地址传递是一样的。因为引用传递可以看作给变量取别名的过程。

引用也是可以作为返回值存在的，但是返回局部变量的引用会因为局部变量存在于战区内导致被系统释放掉。但是函数是可以作左值出现的

例如：

```c++
//返回静态变量引用
int& test02() {
static int a = 20;
return a;
}
//如果函数做左值，那么必须返回引用
int& ref2 = test02();
cout << "ref2 = " << ref2 << endl;
cout << "ref2 = " << ref2 << endl;
test02() = 1000;
cout << "ref2 = " << ref2 << endl;
cout << "ref2 = " << ref2 << endl;
```

本质：**引用的本质在c++内部实现是一个指针常量.**

常量引用

**作用：**常量引用主要用来修饰形参，防止误操作

在函数形参列表中，可以加==const修饰形参==，防止形参改变实参

**示例：**

```C++
//引用使用的场景，通常用来修饰形参
void showValue(const int& v) {
//v += 10;
cout << v << endl;
}
int main() {
//int& ref = 10;  引用本身需要一个合法的内存空间，因此这行错误
//加入const就可以了，编译器优化代码，int temp = 10; const int& ref = temp;
const int& ref = 10;
//ref = 100;  
//加入const后不可以修改变
cout << ref << endl;
//函数中利用常量引用防止误操作修改实参
int a = 10;
showValue(a);
system("pause");
return 0;
}
```

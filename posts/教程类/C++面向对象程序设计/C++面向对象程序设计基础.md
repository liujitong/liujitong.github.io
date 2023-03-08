# C++ 面向对象程序设计基础

前言：这个笔记仅针对具有C语言基础的人来看。不过推荐学完C语言再来看这篇文章

## 如何写一个C++程序

以下是一个示例程序，输出Hello world。编译器我们可以用VScode，VS，DEVC++，也就是说可以用写C语言的编译器写C++。需要注意的是VS2019是支持中文变量的。也就是说，我们可以写以下的代码

```c++
int 中文字符;
```

这只是一个示例程序：

```C++
#include<iostream>
using namespace std;

int main() {
    cout << "Hello world" << endl;
    system("pause");//这一行代码可有可无，取决于自己的编译器
    return 0;
}
```

## 基础知识

C++和C语言在常量和变量的定义基本上是相同的。因为有了C语言的基础，所以这个笔记就不展开叙述了。

C++和C语言一样都可以用`#define`定义常量和`const`定义一个常量

C++同样不支持用其关键字定义变量或者常量，在给变量或者常量起名称时候，不要用C++得关键字，否则会产生歧义。
我们所能见到的C++关键字如下：

| asm        | do           | if               | return      | typedef  |
| ---------- | ------------ | ---------------- | ----------- | -------- |
| auto       | double       | inline           | short       | typeid   |
| bool       | dynamic_cast | int              | signed      | typename |
| break      | else         | long             | sizeof      | union    |
| case       | enum         | mutable          | static      | unsigned |
| catch      | explicit     | namespace        | static_cast | using    |
| char       | export       | new              | struct      | virtual  |
| class      | extern       | operator         | switch      | void     |
| const      | false        | private          | template    | volatile |
| const_cast | float        | protected        | this        | wchar_t  |
| continue   | for          | public           | throw       | while    |
| default    | friend       | register         | true        |          |
| delete     | goto         | reinterpret_cast | try         |          |

对于标识符的命名规则是和C语言相同的

* 标识符不能是关键字
* 标识符只能由字母、数字、下划线组成
* 第一个字符必须为字母或下划线
* 标识符中字母区分大小写

## 数据类型

包括整形，浮点型，字符型，其所占空间与C语言大致类似。同时，都可以利用sizeof这一个关键字输出数据类型所占空间的大小。

可以运行以下代码,来理解一下C++的各种数据类型所占空间的大小:

```C++
#include<iostream>
using namespace std;
int main() {
cout << "short 类型所占内存空间为： " << sizeof(short) << endl;
cout << "int 类型所占内存空间为： " << sizeof(int) << endl;
cout << "long 类型所占内存空间为： " << sizeof(long) << endl;
cout << "long long 类型所占内存空间为： " << sizeof(long long) << endl;
return 0;
}
```

当然了这行代码也可以运行在C语言中，只需要把`cout`改写成printf格式就可以了。

以下是一些转义字符
| **转义字符** | **含义**                                | **ASCII**码值（十进制） |
| ------------ | --------------------------------------- | ----------------------- |
| \a           | 警报                                    | 007                     |
| \b           | 退格(BS) ，将当前位置移到前一列         | 008                     |
| \f           | 换页(FF)，将当前位置移到下页开头        | 012                     |
| **\n**       | **换行(LF) ，将当前位置移到下一行开头** | **010**                 |
| \r           | 回车(CR) ，将当前位置移到本行开头       | 013                     |
| **\t**       | **水平制表(HT)  （跳到下一个TAB位置）** | **009**                 |
| \v           | 垂直制表(VT)                            | 011                     |
| **\\\\**     | **代表一个反斜线字符"\"**               | **092**                 |
| \'           | 代表一个单引号（撇号）字符              | 039                     |
| \"           | 代表一个双引号字符                      | 034                     |
| \?           | 代表一个问号                            | 063                     |
| \0           | 数字0                                   | 000                     |
| \ddd         | 8进制转义字符，d范围0~7                 | 3位8进制                |
| \xhh         | 16进制转义字符，h范围0~9，a~f，A~F      | 3位16进制               |

### 字符型的不同

不同于C语言的是C++的字符串可以直接列用`string`类型声明一个字符串就像下面这样：

```c++
string str ="Hello world";
```

## 运算符

算数/赋值/比较/逻辑完全可以参考C语言的相关知识

## 循环

for/while/do while 在C++中同样适用

## 数组

一维数组和二维数组的定义和用法也和C语言类似。

## 指针

对于指针而言，指针依旧标识地址，可以用&进行取地址的操作

## 函数

对于函数而言，有一个扩充知识：
函数的分文件编写

**作用：**
让代码结构更加清晰

函数分文件编写一般有4个步骤

1. 创建后缀名为.h的头文件  
2. 创建后缀名为.cpp的源文件
3. 在头文件中写函数的声明
4. 在源文件中写函数的定义

**示例：**

```C++
//swap.h文件
#include<iostream>
using namespace std;

//实现两个数字交换的函数声明
void swap(int a, int b);

```

```C++
//swap.cpp文件
#include "swap.h"

void swap(int a, int b)
{
int temp = a;
a = b;
b = temp;
cout << "a = " << a << endl;
cout << "b = " << b << endl;
}
```

```C++
//main函数文件
#include "swap.h"
int main() 
{
int a = 100;
int b = 200;
swap(a, b);
system("pause");
return 0;
}
```

## 结构体

对于结构体和C语言是相同的

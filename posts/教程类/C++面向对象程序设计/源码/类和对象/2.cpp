#include<iostream>
using namespace std;
class example
{
    public:
    example(int a)
    {
        a=1;
        cout<<"现在是有参调用"<<endl;
    }
    example()
    {
        cout<<"现在是无参调用"<<endl;
    }
    //拷贝构造函数
    example (const example &xx)
    {
        example p12=xx;
        cout << "拷贝构造函数!" << endl;
    }
    //析构函数
    ~example() 
    {
        cout << "析构函数!" << endl;
    }
};

void example01()
{
    cout<<"现在调用无参构造函数"<<endl;
    example exp1;
    cout<<"调用完毕1"<<endl;
}
void example02()
{
    cout<<"现在调用有参构造函数"<<endl;
    //第一种调用方式
    example exp2(10);
    //注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
    //example exp2();
    cout<<"完毕2"<<endl;
    //第二种调用方法
    example exp3 = example(10);
    cout<<"完毕3"<<endl;
    example exp4 = example(exp2);
    //2.3 隐式转换法
    example p4 = 10; // example p4 = example(10); 
    example p5 = p4; // example p5 = example (p4); 
    cout<<"完毕4"<<endl;
    //注意2：不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明
    //example p5(p4);
}
int main()
{
    example01();
    example02();
    return 0;
}
//1-1
#include<iostream>
using namespace std;

class Example_e
{
    public:
    Example_e()//构造函数
    {
        cout<<"构造函数调用"<<endl;
    }
    ~Example_e()//析构函数
    {
        cout<<"析构函数调用"<<endl;
    }
};
void example01()
{
    Example_e ex1;
}
int  main()
{
    example01();
    return 0;
}
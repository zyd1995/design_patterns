#include<iostream>
#include<cstdio>

using namespace std;

class singleton{
    static singleton instance;  //静态成员变量
    singleton(){};              //私有构造函数，不允许类外调用new构造实例
public:
    static singleton getinstance(){   //只能通过调用类的getinstance函数构造实例
        if(instance==NULL)           //当实例未构造时才能构造实例
            instance=new singleton();  
        return instance;
    }
};

int main(){
    singleton s=singleton::getinstance();
    singleton s1=singleton::getinstance();//s,s1是相同的实例 s==s1为true
}
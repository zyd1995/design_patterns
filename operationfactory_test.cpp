////简单工厂模式
#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

class operation{
public:
    operation(){}
    double number1,number2;
    virtual double getresult(){}
};

class operationadd:public operation{
    double getresult(){
        return number1+number2;
    }
};

class operationsub:public operation{
    double getresult(){
        return number1-number2;
    }
};

class operationmul:public operation{
    double getresult(){
        return number1*number2;
    }
};

class operationdiv:public operation{
    double getresult(){
        return number1/number2;
    }
};

//简单工厂类
class operationfactory{
public:
    static operation createoperate(char operate){
        operation oper;
        switch(operate){
            case '+':
                return operationadd();
            case '-':
                return operationsub();
            case '*':
                return operationmul();
            case '/':
                return operationdiv();
        }
    }
};

int main(){
    operation oper;
    oper=operationfactory::createoperate('+');  //通过简单工厂类构造子类对象
    double n1,n2;
    cin>>n1>>n2;
    oper.number1=n1;
    oper.number2=n2;
    cout<<oper.getresult()<<endl;   //动态绑定
    return 0;
}



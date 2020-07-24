#include<iostream>
#include<cstdio>

using namespace std;

class singleton{
    static singleton instance;
    static readonly object syncroot=new object();
    singleton(){};
public:
    static singleton getinstance(){
        if(instance==NULL){    //双重锁定，避免多线程同时创建时出错
            lock(syncroot){    //锁定，当一个线程位于代码的临界区时，另一个线程不进入临界区
                if(instance==NULL) 
                    instance=new singleton();
            }
        }
        return instance;

    }
};

int main(){
    singleton s=singleton::getinstance();
    singleton s1=singleton::getinstance();//s,s1是相同的实例
}
#include<iostream>
using namespace std ;
class B{
    public:
    int a,b;
int add(){
    return a+b;
}
void operator+ (B &obj){
    int value1 = this->a;
int value2=obj.a;
cout<<"output: "<<value2-value1<<endl;
cout<<"tera bhai seedhe maut"<<endl;
}
void operator() (){
    cout<<"seedhe maut ke bina kya jeevan hai"<<endl;
}
};

//run time polymorphism
class animal{
    public:
    void speak(){
        cout<<"speaking"<<endl;
    }
};
class dog: public animal{
public:
void speak(){
    cout<<"barking"<<endl; 
}
};
int main(){
B obj1,obj2;
obj1.a=10;
obj2.a=20;
obj1 + obj2;
obj1();

dog d1;
d1.speak();//function over riding

return 0;
}
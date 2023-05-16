#include<iostream>
using namespace std ;
// hirerarical inheritance...
class a{
public:
void func1(){
    cout<<"inside func 1"<<endl;
}
};
class d{
public:
void func4(){
cout<<"inside func 4 "<<endl;
}
};
class b : public a{
public:
void func2(){
cout<<"inside function 2"<<endl;
}
};
class c : public a ,public d{
void func3(){
    cout<<"inside func 1"<<endl;
}
};
int main(){
a obj1;
obj1.func1();
b obj2;
obj2.func1();
obj2.func2();

c obj3;
obj3.func1();
obj3.func4();


return 0;
}
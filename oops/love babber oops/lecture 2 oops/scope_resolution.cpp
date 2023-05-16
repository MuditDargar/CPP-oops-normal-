#include<iostream>
using namespace std ;
class a{
    public:
    void func(){
       cout<<"i am a"<<endl ; 
    }
};
class b{
    public:
    void func(){
        cout<<"i am b"<<endl;
    }
};
class c: public a,public b{

};
int main(){
c obj;
//obj.func(); not work kiska func hai kaise specify kare
// iss samasya ko hatane ke liye
// scope resolution ka use lena
obj.a::func();

return 0;
}
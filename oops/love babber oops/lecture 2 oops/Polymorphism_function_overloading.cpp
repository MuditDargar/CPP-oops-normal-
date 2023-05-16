#include<iostream>
using namespace std ;
class a{
    public:
    void sayhelo(){
        cout<<"hello world"<<endl;
    }
    int sayhelo(int n,string name){
        cout<<"hello mudit"<<endl;
        return 1;
    }

void sayhelo(string name){
    cout<<"hello  rajuuu"<<endl;
}
};
int main(){
a obj;
obj.sayhelo(10,"mudit");
obj.sayhelo("mudit");
obj.sayhelo();


return 0;
}
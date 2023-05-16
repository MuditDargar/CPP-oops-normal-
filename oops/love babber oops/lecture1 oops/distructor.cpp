#include<iostream>
using namespace std ;
class test{
    public:
    test(){
        cout<<"\n Constructor executed";
    }
    ~test(){
        cout<<"\n Destructor executed";
    }
};
int main(){
test t;

return 0;
}
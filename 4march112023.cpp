#include<iostream>
#include<string.h>
using namespace std;
class student{
public:
static int  roll_no;
int id1=0;
int id2;

student(int x){
id2=id1;
id1 =x;
cout<<"object "<<x<<endl;
cout<<"constructor of "<<id1<<endl;
id1++;
}
~student(){
cout<<"object "<<id2<<endl;
cout<<"destructor "<<id2<<endl;
}

};

student obj2 = student(2);
int main(){
student s1();
}
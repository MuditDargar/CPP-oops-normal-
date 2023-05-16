#include<iostream>
using namespace std ;
class student{
// private class / modifier ko aap class ke ander hi access kar sakhte ho
    private:
 int roll_no;
 char name[100];
 int student_id;

 void puneet(){
    cout<<roll_no<<endl;
 }
};
int main(){
student mudit;
// cout<<"roll_no"<<mudit.roll_no<<endl;
// cout<<"name"<<mudit.name<<endl;
return 0;
}
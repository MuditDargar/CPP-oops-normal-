#include<iostream>
#include<string.h>

//construcotr with distructor program

using namespace std;
class student{
public:
int roll_no;
int student_id;
string s;
 student();
  ~student(){
    cout<<"program executed successfully";
}


 void show(){
    cout<<roll_no<<endl;
    cout<<student_id<<endl;
    cout<<s<<endl;


}
};
 student :: student(){
cout<<"enter your important details"<<endl;
cin>> roll_no;
cin>>student_id;
cin>>s;
}

int main(){
student s1;

s1.show();

return 0;
}
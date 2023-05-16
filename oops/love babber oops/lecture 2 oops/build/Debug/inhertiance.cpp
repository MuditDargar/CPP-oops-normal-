#include<iostream>
using namespace std ;
class human{
    public:
    int height ;
    int weight;
    int age;

    public:
    int getage(){
        return this->age ;
    }
  void setweight(int n){
     this->weight = n;
  }
};
// inheritance apply 
// inherit ke baad male mae bhi human ki property aa jaayegi..
class male: public human{
 public:
 string color;
 void sleep(){
    cout<<"male is sleeping"<<endl;
 }
};
int main(){
male object1;
cout<<object1.age<<endl;
cout<<object1.color<<endl;
cout<<object1.weight<<endl;
cout<<object1.height<<endl;
cout<<"!!!!!!"<<endl;
object1.sleep();
object1.setweight(84);
cout<<object1.weight<<endl;
return 0;
}
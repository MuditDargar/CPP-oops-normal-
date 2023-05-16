#include<iostream>
#include<vector>
using namespace std ;
int main(){
vector<int>v ;
v.push_back(1);
v.emplace_back(3);
for (auto it : v)
{
    cout<<it<<endl;
}


return 0;
}
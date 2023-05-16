#include <iostream>
#include <string.h>
using namespace std;
class rolex
{
    int health;

public:

    // deafault constructor
    rolex()
    {
        cout << "the rolex is the fabulous " << endl;
   
    }
    // this function used
    rolex(int health)
    {
        this->health = health;
    }
    int gethealth()
    {
        return health;
    }
    int sethealth(int h)
    {
        health = h;
    }
    void print()
    {
        cout << "health is " << this->health << endl;
    }
    // copy constructor
    rolex(rolex &temp)
    {
        cout << "copy constructor call ed" << endl;
        this->health = temp.health;
    }
};
int main()
{
    rolex raju;
    raju.sethealth(45);

    // copy comstructor...
    rolex ritesh(raju);

    // iss line ka matlb yeah hai
    // ki ritesh.health = raju.health hai..
    // rajuke health  ki copy ritesh ki health mae ho gyi hai

    raju.print();
    cout << sizeof(raju) << endl;

    return 0;
}
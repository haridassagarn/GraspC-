#include <iostream>
using namespace std;

class Base
{
    public:
    Base()
    {
        cout << "in Base() " << endl;
    }
    virtual ~Base()
    {
         cout << "in ~Base() " << endl;
    }
    
};

class Derived:public Base
{
    public:
    Derived()
    {
         cout << "in Derived() " << endl;
    }
    ~Derived()
    {
         cout << "in ~Derived() " << endl;
    }
    
};

int main()
{
   Base* b = new Base();
   delete b;
   
    Derived* d = new Derived();
    delete d;
    
    Base* bd = new Derived();
    delete bd;
  return 0;
    
}

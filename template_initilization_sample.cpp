/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class testimpl
{
    public:
    testimpl()
    {
        cout<<"in test impl" << endl;
    }
    
};


template<typename T>
class Test
{
    
    private:
    Test()
    {
        T obj;
        cout<< "in test constructor " << endl;
    }
    static Test instance;
    
};


template<typename T>
Test<T> Test<T>::instance;

template class Test<testimpl>;

int main()
{
    cout<<"Hello World";

    return 0;
}

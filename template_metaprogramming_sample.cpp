/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

template<int a, int b>
struct gcd
{
    inline  static constexpr int value = gcd<a,b%a>::value;
    
};

template<int a>
struct gcd<a,0>
{
    inline constexpr static int value = a;
    
};


int main()
{
    
    static_assert(gcd<5,15>::value==5);
    cout<<"Hello World";

    return 0;
}

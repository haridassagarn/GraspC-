/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
struct AStruct{
   using ASubtype = int;
};

class AStructB{
public:   
   using ASubtype = const char*;
};

template<typename T> void AfunctionTemplate(typename T::ASubtype value) {
   std::cout << " Type contains ASubtype = TRUE " << std::endl;
   std::cout << " Value = " << value << std::endl;
}
int main()
{
    cout<<"Hello World" << endl;
    AfunctionTemplate<AStruct>(200);
    AfunctionTemplate<AStructB>("PARAMETER");
    //AfunctionTemplate(600) this generates compiler error

    return 0;
}

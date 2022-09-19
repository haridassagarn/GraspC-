/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

template<class A,class B,class C>
struct tuple3{
  
  tuple3(){};
  tuple3(const A& a,const B& b,const C& c):a(a),b(b),c(c)
  {
      
  };
  A a;
  B b;
  C c;
  
  
    
};

template<class A,class B,class C>
auto get_TupleA(const tuple3<A,B,C>& t)-> A
{
    return t.a;
}

template<class A,class B,class C>
auto get_TupleB(const tuple3<A,B,C>& t)-> B
{
    return t.b;
}

template<class A,class B,class C>
auto get_TupleC(const tuple3<A,B,C>& t)-> C
{
    return t.c;
}

template<class A,class B,class C>
auto print_tuple(const tuple3<A,B,C>& t) -> void
{
    cout << t.a << "," <<  t.b << "," << t.c;
}
int main()
{
    cout<<"Hello World" <<endl;
    
    tuple3<int,int,string> t(1,2,"hello");
    cout<< get_TupleB(t) <<endl;
    cout<< get_TupleC(t) <<endl;
    
    print_tuple(t);
    return 0;
}

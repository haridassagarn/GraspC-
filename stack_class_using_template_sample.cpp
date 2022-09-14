/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <deque>

using namespace std;

struct _stack_empty_error: public std::exception{
    
    const char * what() const throw()
    {
        cout << "ERROR------ stack is empty " << endl;
    }
    
};


template<class T>
class Stack
{
  private:
  std::deque<T> _stack;
  
  public:
      void push(const T& t)
      {
          _stack.push_back(t);
      };
      
      T pop()
      {
          if(_stack.empty())
          {
              throw _stack_empty_error();
          }
          T obj = _stack.back();
          _stack.pop_back();
          return obj;
      };
      
      T peek()
      {
          if(_stack.empty())
          {
              throw _stack_empty_error();
          }
          T obj = _stack.back();
          return obj;
          
      };
    
    int size()
    {
        return _stack.size();
    };
    
    void clear()
    {
        return _stack.clear();
    };
    
    void print()
    {
          if(_stack.empty())
          {
              throw _stack_empty_error();
          }
          
          for(const auto &x: _stack)
              cout << "element :  "<< x << endl;
          cout << "\n";
    };
    
    
};


int main()
{
   Stack<int> s1;
   s1.push(1);
   s1.push(2);
   
   s1.print();
   
  cout <<  s1.peek() << endl;
  
  s1.pop();
  s1.print();


   s1.push(3);
   s1.push(4);
   s1.push(5);
   
   s1.print();
   
   s1.clear();
   s1.print();
    return 0;
}

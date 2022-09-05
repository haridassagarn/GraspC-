#include <iostream>
using namespace std;

template<class sometype>
sometype sum_two_numbers(sometype a,sometype b)
{
  return a+b; 
}

int main(int argc,char* argv[])
{
  double a=22.22,b=11.11;
  
  std::cout << sum_two_numbers(a,b) << std::endl;
  
  int c =10,d=20;
  std::cout << sum_two_numbers(c,d) << std::endl;
  
  return 0;
  
}

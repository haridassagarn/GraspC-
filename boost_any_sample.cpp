
#include <iostream>
#include <string>

#include <boost/any.hpp>

using namespace std;

int main(int argc,char* argv[])
{
  any w;
  any x{2.0};
  vector<any> y {55, "hello"};
  any z = string("text");
  
  if(!x.empty())
  {
   cout << x.type().name() <<endl; 
  }
  
  int a = any_cast<int>(y[0]);
  
  cout << " value of a is:" << a <<endl;
  
  string text = any_cast<string>(y[1]);
  
   cout << " text name  is:" << text <<endl;
  
  try{
   int valtxt = any_cast<int>(y[1]);
  }
  catch(const bad_any_cast& e)
  {
    cout << "wrong type " <<endl;
  }
  
  for(any a:y)
  {
   int* value = any_cast<int>(&a);
   if(value!=nullptr)
   {
      cout << "value int is " << *value <<endl;
   }
    const char** text = any_cast<const char*>(&a)
    if(text!=nullptr)
    {
      cout << "text is " << *text <<endl;
    }
  }
  return 0;
}

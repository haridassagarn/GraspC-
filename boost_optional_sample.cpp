#include "stdafx.h"


class Address
{
  Public:
         Address(string streetname):
                                    streetname(streetname){}
         string streetname;
};
class Person
{
  Public:
        Person(string firstname,string lastname):
                  firstname(firstname),lastname(lastname){}
        string firstname,lastname;
        optional<string> middlename;
        optional<Address> address;
 };


int main()
{
  Person p{"John","J"};
  
  cout<< p.middlename << endl; // this outpts boolean (as number '0' ) since middlename is not initialized
  cout << *p.middlename <<endl; //this results in assertion failure
  
  p.middlename = "Cocomelon";
  //so, we check if it is initialized
  if(p.middlename)
  {
    cout << *p.middlename <<endl;
  }
  
  p.address = Address{"Cocomelon street"};
  
  if(p.address)
  {
   cout << p.address->streetname <<endl; // or cout<< (*p.address).streetname <<endl;
  }
 
  return 0;
}

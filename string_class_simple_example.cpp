/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

class String
{
    private:
        char* res;
        int len;
        
    public:
        String():res(nullptr),len(0){cout << "dc" << endl;};
        String(const char* txt)
        {
            len = strlen(txt);
            res = new char[len+1];
            strcpy(res,txt);
        };
        String(const String& s)
        {

                len = s.len;
                res = new char[len+1];
                strcpy(res,s.res);
        };
        
        String( String&& s)
        {
            cout << "in move constructor" << endl;
                len = s.len;
                res = s.res;
                s.res=nullptr;
                s.len=0;
        };
        
        
        
       /* String& operator=(const String& s)
        {
            if(this!=&s)
            {
                delete []res;
                len = s.len;
                res = new char[len+1];
                strcpy(res,s.res);
            }
           return *this;
        };*/
        
        String& operator=( String s)
        {
            swap(*this,s);
            return *this;


        };
        
        void swap(String& s1,String&s2)
        {
            std::swap(s1.res,s2.res);
            std::swap(s1.len,s2.len);
            
        }
        
      /*  String& operator=(const char* txt)
        {
                len = strlen(txt);
                res = new char[len+1];
                strcpy(res,txt);
                return *this;
        };*/
        
        
        
        int length()
        {
            return len;
        };
        
        ~String()
        {
            cout << "in destructor " << endl;
            if(res)
            {
                delete[] res;
                len = 0;
                res = nullptr;
            }
        }
        
        friend ostream& operator<<(ostream& out,const String& s);
        friend istream& operator>>(istream& in,const String& s);
};


ostream& operator<<(ostream& out,const String& s)
{
    out << s.res;
    return out;
}

istream& operator>>(istream& in,const String& s)
{
    in >> s.res;
    return in;
}

int main()
{

   String s1;
   String s2 = "Hi";
   
   String temp = "iamtemp";
   String s3 = s2;
   String s4 ;
   s4 = s3;
   
   String s5;
   s5 = "World";
   
     cout << s2.length() << endl;
     cout << s2 << endl;
     cout << s5 << endl;
     //cin >> s1;
      
    // cout << s1;
  
  
    String s6 = std::move(s2);
   //  cout << s2 << endl;
     cout << s6 << endl;
    s5 = std::move(temp);
   cout << s5 << endl;
  // cout << temp << endl;

    return 0;
}

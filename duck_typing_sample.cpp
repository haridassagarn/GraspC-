/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

template<class T>
void showDetails(const T& obj)
{
    
    cout << obj.getsize()<<endl;
    cout << obj.Name()<<endl;
    
}


class Circle
{
    private:
    double m_radius;
    
    public:
    Circle():m_radius(0){};
    Circle(double rad):m_radius(rad){};
    
    double getsize () const
    {
        return m_radius*3.14*3.14;
    };
    
    const char* Name() const
    {
        return "Circle";
    };
    
};
    
    
class Square
{
    private:
    double m_side;
    
    public:
    Square():m_side(0){};
    Square(double side):m_side(side){};
    
    double getsize () const
    {
        return m_side*m_side;
    };
    
    const char* Name() const
    {
        return "Square";
    };
    
};

int main()
{
    //cout<<"Hello World " << twopow<8>::val << endl;
    
    Circle c(10);
    Square s(2);
    
    showDetails(c);
    showDetails(s);

    return 0;
}

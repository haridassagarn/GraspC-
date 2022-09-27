template<int n>
struct twopow
{
    static inline constexpr int val = 2*twopow<n-1>::val;
};


template<>
struct twopow<0>
{
    static inline constexpr int val =1;
};

int main()
{
    cout<< twopow<8>::val << endl;
    return 0;
}

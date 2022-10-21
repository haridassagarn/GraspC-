#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    long long int ans = 1;
    long int xx = x;
    
    while(n)
    {
        if(n%2==0)
        {
            xx=(xx%m*xx%m)%m;
            n=n/2;
        }
        else
        {
            ans=(ans%m*xx%m)%m;
            n=n-1;
        }
    }
    //std::cout << "ans is: " << ans << std::endl;
    return ans;
}

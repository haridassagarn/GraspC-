#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>> pascalT(n);
    
    for(int i=0;i<n;i++)
    {
        pascalT[i].resize(i+1);
        pascalT[i][0]=pascalT[i][i]=1;
        
        for(int j =1;j<i;j++)
        {
            pascalT[i][j]=pascalT[i-1][j]+pascalT[i-1][j-1];
        }
    }  // Write your code here.
    
    return pascalT;
}

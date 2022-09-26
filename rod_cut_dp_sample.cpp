int f(vector<int> &price, int n,int index,vector<vector<int>> &dp)
{
    if(index == 0)
    {
        return price[0]*n;
    }
    if(dp[index][n]!=-1)
    {
        return dp[index][n];
    }
    
    if(n==0)
    {
        return 0;
    }
    
    int nottake = f(price,n,index-1,dp);
    
    int take = INT_MIN;
    
    int rodlength = index+1;
    if(rodlength<=n)
    {
        take = price[index]+f(price,n-rodlength,index,dp);
    }
    return dp[index][n] = max(take,nottake);
}



int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
	// Write your code here.
    return f(price,n,n-1,dp);
}


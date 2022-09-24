int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    int temp[n];
    for(int k=0;k<n;k++)
    {
        temp[k]=1;
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
                temp[i]=max(temp[i],temp[j]+1);
            }
        }
    }
    int maxindex = 0;
    for(int m=0;m<n;m++)
    {
        if(m!=0 && temp[m]>temp[maxindex])
        {
            maxindex= m;
        }
    }
    
    return temp[maxindex];
}

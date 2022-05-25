// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    vector<vector<int> >dp;
    int rec(int arr[],int n,int i,int sum)
    {
        if(sum==0)
        {
            return 1;
        }
        if(i>=n or sum<0)
        {
            return 0;
        }
        if(dp[i][sum]!=-1)
        {
            return dp[i][sum];
        }
        
        int op1=rec(arr,n,i+1,sum-arr[i]);
        int op2=rec(arr,n,i+1,sum);
        return dp[i][sum]=op1 or op2;
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        if(sum&1)
        {
            return 0;
        }
        sum/=2;
        dp=vector<vector<int> >(N+1,vector<int>(sum+1,0));
        for(int i=0;i<=N;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                int op1=dp[i-1][j];
                int op2=0;
                if(j-arr[i-1]>=0)
                {
                    op2=dp[i-1][j-arr[i-1]];
                }
                dp[i][j]=op1 or op2;
            }
        }
        return dp[N][sum];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends

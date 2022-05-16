// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int a[], int n, int k)
	{
	    // Complete the function
	    map<int,int> m;
	    int sum=0;
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=a[i];
	        int c=(sum%k+k)%k;
	        if(c==0)
	        {
	            ans=max(ans,i+1);
	        }
	        else if(m.find(c)!=m.end())
	        {
	            ans=max(ans,i-m[c]);
	        }
	        else
	        m[c]=i;
	    }
	    return ans;
	    //
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends

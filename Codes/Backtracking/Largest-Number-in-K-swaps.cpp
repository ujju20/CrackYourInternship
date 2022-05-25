// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    string rec(string &s,int i,int k)
    {
        if(k==0 or i>=s.size())
        {
            return s;
        }
        //string temp=s;
        for(int j=i;j<s.size();j++)
        {
            if(s[j]>s[i])
            {
                swap(s[i],s[j]);
                s=max(s,rec(s,i+1,k-1));
                swap(s[i],s[j]);
            }
        }
        s=max(s,rec(s,i+1,k));
        return s;
    }
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       return rec(str,0,k);
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends

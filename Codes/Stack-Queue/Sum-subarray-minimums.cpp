class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int> s;
        int mod=1e9+7;
        vector<int> prevSmaller(n,0),nextSmaller(n,0);
        for(int i=0;i<n;i++)
        {
            nextSmaller[i]=n-i-1;
            prevSmaller[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            while(!s.empty() and arr[s.top()]>arr[i])
            {
                nextSmaller[s.top()]=i-s.top()-1;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() and arr[s.top()]>=arr[i])
            {
                prevSmaller[s.top()]=s.top()-i-1;
                s.pop();
            }
            s.push(i);
        }
        long long int ans=0;
        for(int i=0;i<n;i++)
        {
            long long int a=(nextSmaller[i]+1)%mod;
            long long int b=(prevSmaller[i]+1)%mod;
            long long int c=arr[i]%mod;
            ans=(ans+(a*b*c)%mod)%mod;
            //ans%=mod;
        }
        return ans;
    }
};

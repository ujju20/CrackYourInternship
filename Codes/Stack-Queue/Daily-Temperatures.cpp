class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        stack<pair<int,int> > s;
        vector<int> ans(n);
        ans[n-1]=0;
        s.push({t[n-1],n-1});
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty() and s.top().first<=t[i])
            {
                s.pop();
            }
             if(s.size()>0)
            {
                ans[i]=abs(i-s.top().second);
            }
            else
            ans[i]=0;
            s.push({t[i],i});
           
        }
        return ans;
    }
};

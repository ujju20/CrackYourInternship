class Solution {
    vector<vector<int> > ans;
    vector<int> temp;
    void rec(vector<int> v,int n,int idx,int sum)
    {
        if(sum==0)
        {
            ans.push_back(temp);
            return;
        }
        if(idx>=n or sum<0)
        {
            return;
        }
        
        for(int i=idx;i<n;i++)
        {
            if(i!=idx and v[i-1]==v[i])
                continue;
            temp.push_back(v[i]);
            rec(v,n,i+1,sum-v[i]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        int n=c.size();
        sort(c.begin(),c.end());
        rec(c,n,0,target);
        return ans;
    }
};

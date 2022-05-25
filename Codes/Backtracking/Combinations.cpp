class Solution {
    vector<vector<int> > ans;
    vector<int> temp;
    void rec(int n,int k,int idx)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<=n;i++)
        {
            temp.push_back(i);
            rec(n,k,i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        rec(n,k,1);
        return ans;
    }
};

class Solution {
    vector<vector<int> > ans;
    vector<int> temp;
    void rec(vector<int> nums,int n,int idx)
    {
        ans.push_back(temp);
        for(int i=idx;i<n;i++)
        {
            if(i!=idx and nums[i-1]==nums[i])
                continue;
            temp.push_back(nums[i]);
            rec(nums,n,i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        rec(nums,n,0);
        return ans;
    }
};

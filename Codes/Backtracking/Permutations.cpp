class Solution {
    vector<vector<int> > ans;
    void rec(vector<int> nums,int l)
    {
        if(l>=nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=l;i<nums.size();i++)
        {
            if(i>l and nums[l]==nums[i])
                continue;
            swap(nums[i],nums[l]);
            rec(nums,l+1);
            //swap(nums[i],nums[l]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int l=0;
        sort(nums.begin(),nums.end());
        rec(nums,l);
        return ans;
    }
};

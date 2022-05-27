class Solution {
    int ans=0;
    bool check(vector<int> nums)
    {
        for(int i=0;i<nums.size();i++)
        {
            if((i+1)%nums[i]!=0 and nums[i]%(i+1)!=0)
            {
                return false;
            }
        }
        return true;
    }
    void rec(vector<int> nums,int l)
    {
        if(l==nums.size())
        {
            ans++;
            return;
        }
        for(int i=l;i<nums.size();i++)
        {
            swap(nums[i],nums[l]);
            if((l+1)%nums[l]==0 or nums[l]%(l+1)==0)
                rec(nums,l+1);
            swap(nums[i],nums[l]);
        }
    }
public:
    int countArrangement(int n) {
        vector<int> nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        
        rec(nums,0);
        return ans;
    }
};

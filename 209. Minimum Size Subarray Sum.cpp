class Solution {
public:
    bool check(vector<int> &nums,int len,int target)
    {
        int sum=0;
        for(int i=0;i<len;i++)
        {
            sum+=nums[i];
        }
        if(sum>=target) return true;
        for(int i=1;i<nums.size()-len+1;i++)
        {
            sum-=nums[i-1];
            sum+=nums[i+len-1];
            if(sum>=target) return true;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=1;
        int high=nums.size();
        int ans=0;
        while(low<=high)
        {
            int mid=high-(high-low)/2;
            if(check(nums,mid,target))
            {
                ans=mid;
                high=mid-1;
            }
            else
             low=mid+1;             
        }
        return ans;
    }
};

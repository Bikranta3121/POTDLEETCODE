class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return {};
        int start=0;
        vector<string> ans;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-1 == nums[i-1])
            {
                continue;
            }
            else
            {
                if(start==i-1) ans.push_back(to_string(nums[start]));
                else
                {
                    string str=to_string(nums[start])+"->"+to_string(nums[i-1]);
                    ans.push_back(str);
                }
                 start=i;
            }
            
        }
               if(start==nums.size()-1) ans.push_back(to_string(nums[start]));
                else
                {
                    string str=to_string(nums[start])+"->"+to_string(nums[nums.size()-1]);
                    ans.push_back(str);
                }
        
        return ans;
    }
};

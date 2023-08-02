class Solution {
public:
    void f(vector<int> &nums,vector<vector<int>> &ans,vector<int> &vis,vector<int> &ds)
    {
        if(vis.size()==ds.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<vis.size();i++)
        {
           if(!vis[i])
           {
            ds.push_back(nums[i]);
            vis[i]=1;
            f(nums,ans,vis,ds);
            vis[i]=0;
            ds.pop_back();
           }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vis(nums.size(),0);
        vector<int> ds;
        f(nums,ans,vis,ds);
        return ans;
    }
};

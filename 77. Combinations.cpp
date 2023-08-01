class Solution {
public:
    
    void solve(int i,int n,int k,vector<vector<int>> &combinations,vector<int> ans)
    {
        if(k==0)
        {
            combinations.push_back(ans);
            return;
        }
        for(int j=i;j<=n;j++)
        {
               ans.push_back(j);
               solve(j+1,n,k-1,combinations,ans);
               ans.pop_back();          
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> ans;
        solve(1,n,k,combinations,ans);
        return combinations;
    }
};

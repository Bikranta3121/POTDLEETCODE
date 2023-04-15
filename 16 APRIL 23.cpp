class Solution {
public:
    int rec(int i,int k,vector<vector<int>> &dp,vector<vector<int>>& piles)
    {
        if(dp[i][k]!=0) return dp[i][k];
        if(i==piles.size() || k==0) return 0;
        int ans=rec(i+1,k,dp,piles);
        int prefix=0;
        
        for(int j=0;j<k and j<piles[i].size();j++)
        {
            prefix+=piles[i][j];
            ans=max(ans,prefix+rec(i+1,k-j-1,dp,piles));
        }
        return dp[i][k]=ans;

    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
       int n=piles.size();
       vector<vector<int>> dp(n+1,vector<int>(k+1,0));
       rec(0,k,dp,piles);        
       return dp[0][k];
    }
};

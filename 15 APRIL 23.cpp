class Solution {
public:
    // bool ispalindrome(string &ans)
    // {
    //     int i=0;
    //     int j=ans.size()-1;
    //     while(i<j)
    //     {
    //         if(ans[i]!=ans[j]) return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
   
    // int rec(int i, int j,vector<vector<int>> &dp,string ans,string s)
    // {
    //    if(i>=s.size() || j>=s.size())
    //     return 0;
    //     if(s[i]==ans[j]) return dp[i][j]=1+rec(i+1,j+1,dp,ans,s);
    //     return dp[i][j]=max(rec(i+1,j,dp,ans,s),rec(i,j+1,dp,ans,s));
             
    // }
    int longestPalindromeSubseq(string s) {
        string ans=s;
        reverse(ans.begin(),ans.end());
        int n=s.size();
        vector<vector<int>> dp(s.size()+1,vector<int> (s.size()+1,0));
        for(int i=1;i<=s.size();i++)
        {
            dp[i][i]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
               if(s[i-1]==ans[j-1]) dp[i][j]=1+dp[i-1][j-1];
               else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
         return dp[n][n];
       // return max_size;
    }
};

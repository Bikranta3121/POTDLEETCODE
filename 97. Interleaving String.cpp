class Solution {
public:
    bool solve(int i,int j,int k,string s1, string s2, string s3,vector<vector<vector<int>>> &dp)
    {
        if(k>=s3.size() and i>=s1.size() and j>=s2.size()) return true;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        bool take=false;
      
        if(i<s1.size() and s1[i]==s3[k])
        {
           take=take|solve(i+1,j,k+1,s1,s2,s3,dp);
        }
        if(j<s2.size() and s2[j]==s3[k])
        {
            take=take|solve(i,j+1,k+1,s1,s2,s3,dp);
        }
        return dp[i][j][k]=take;
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        vector<vector<vector<int>>> dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,0)));
        dp[s1.size()][s2.size()][s3.size()]=1;
        for(int i=s1.size();i>=0;i--)       
         {
           
            for(int j=s2.size();j>=0;j--)
            {   
                
                for(int k=s3.size()-1;k>=0;k--)
                {
                     bool take=false;    
                    if(i<s1.size() and s1[i]==s3[k])
                    {
                        take=take|dp[i+1][j][k+1];
                    }
                    if(j<s2.size() and s2[j]==s3[k])
                    {
                        take=take|dp[i][j+1][k+1];
                    }
                    dp[i][j][k]=dp[i][j][k]|take;
                }
            }
        } 

        return dp[0][0][0];
    }
};

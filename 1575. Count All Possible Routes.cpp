class Solution {
public:
    int  mod=1e9+7;;
    
    int func(int start,int finish,int fuel,vector<int>& locations,vector<vector<int>> &dp)
    {
        if(fuel<0) return 0;
        if(dp[start][fuel]!=-1)  return dp[start][fuel];
          int ans=0;
         if(start==finish) ans++;
        for(int i=0;i<locations.size();i++)
        {
            
             if(i!=start)   ans=(ans%mod + func(i,finish,fuel-(abs(locations[start]-locations[i])),locations,dp)%mod)%mod;
                         
        }
         return dp[start][fuel]=ans%mod;
       
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size(),vector<int>(fuel+1,-1));
        return func(start,finish,fuel,locations,dp);
    
    }
};

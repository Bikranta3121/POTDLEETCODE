typedef long long int ll;
class Solution {
public:
    int dfs(int i,vector<int> &vis,vector<vector<int>>& bombs)
    {
        vis[i]=1;
        ll xi=bombs[i][0];
        ll yi=bombs[i][1];
        ll ri=bombs[i][2];
        int count=1;
        for(int j=0;j<bombs.size();j++)
        {
                
               if(!vis[j])
               { 
                 ll x_i=bombs[j][0]-xi;
                 ll y_i=bombs[j][1]-yi;
                 if((x_i*x_i)+(y_i*y_i) <= (ri*ri))
                 {
                    count+=dfs(j,vis,bombs);
                 }
               }
        }
        return count;
        
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int max_count=1;
        int n=bombs.size();
       
        for(int i=0;i<n;i++)
        {
              vector<int> vis(n,0);            
              max_count=max(max_count,dfs(i,vis,bombs));
        }
        return max_count;
    }
};

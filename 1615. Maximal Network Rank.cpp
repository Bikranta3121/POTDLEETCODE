class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        for(int i=0;i<roads.size();i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int max_val=0;
        for(int i=0;i<n;i++)
        {
            unordered_set<int> st;
            for(int k:adj[i])
               st.insert(k);
            for(int j=0;j<n;j++)
                {
                    if(i==j)
                    {
                        int x=adj[i].size();
                        for(int k:adj[i])
                        {
                            int y=adj[k].size();
                            max_val=max(max_val,x+y-1);
                        }
                    }
                    else if(st.find(j)!=st.end())
                    {
                        continue;
                    } 
                    else
                    {
                        int x=adj[i].size();
                        int y=adj[j].size();
                        max_val=max(max_val,x+y);
                    }          

                }
            }
           

        



        
        return max_val;
    }
};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> row{0,-1,0,1};
        vector<int> col{-1,0,1,0};
        int count=0;
       for(int i=0;i<n;i++)
       {
          for(int j=0;j<m;j++)
           {
               if(grid[i][j]==0)
               {
                   int flag=0;
                   queue<pair<int,int>> q;
                   q.push({i,j});
                   grid[i][j]=1;
                   while(!q.empty())
                   {
                       int r=q.front().first;
                       int c=q.front().second;
                       q.pop();
                       for(int k=0;k<4;k++)
                       { 
                           int x=row[k];
                           int y=col[k];
                           if(r+x<0 || r+x>=n || c+y<0 || c+y>=m)
                           {
                               flag=1;
                               continue;
                           }
                           if(!grid[r+x][c+y])
                           { 
                              q.push({r+x,c+y});
                              grid[r+x][c+y]=1;
                           }

                       }
                       
                   }
                   if(!flag) count++;
               }
           }

       }
       return count; 
    }
};

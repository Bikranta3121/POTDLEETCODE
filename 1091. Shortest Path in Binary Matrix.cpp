class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        vector<int> row={0,-1,-1,-1,0,1,1,1};
        vector<int> col={-1,-1,0,1,1,1,0,-1};

        if(grid[0][0]==1) return -1;
        q.push({{0,0},1});
        grid[0][0]=1;
        int d_row=grid.size()-1;
        int d_col=d_row;
        while(!q.empty())
        {
           int r=q.front().first.first;
           int c=q.front().first.second;
           int dist=q.front().second;
           q.pop();
           if(r==d_row and c==d_row)
            return dist;
           for(int k=0;k<8;k++)
           {
               int x=r+row[k];
               int y=c+col[k];
               if(x<0 || y<0 || x>d_row || y>d_row) continue;
               if(grid[x][y]==0)
               {
                   q.push({{x,y},dist+1});
                   grid[x][y]=1;
               }
           } 
        }
        return -1;
    }
};

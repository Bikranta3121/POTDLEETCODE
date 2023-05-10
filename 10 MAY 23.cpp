class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        int row=0;
        int col=0;
        int count=1;
        while(mat[n/2][(n-1)/2]==0)
        {
           while(col<n and mat[row][col]==0)//moving right
           {
               mat[row][col]=count;
               count++;
               col++;
           }
           col--;
           row++;
           while(row<n and mat[row][col]==0)//moving down
           {
               mat[row][col]=count;
               count++;
               row++;
           }
           row--;
           col--;
           while(col>=0 and mat[row][col]==0)//moving left
           {
               mat[row][col]=count;
               count++;
               col--;
           }
           col++;
           row--;
           while(row>=0 and mat[row][col]==0)//moving top
           {
               mat[row][col]=count;
               count++;
               row--;
           }
           row++;
           col++;
        }
        return mat;
    }
};

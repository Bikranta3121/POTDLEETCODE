class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int col=0;
        int row=0;
        int m=matrix[0].size();
        int n=matrix.size();
        while(col<m)
        {
            int r=0;
            int c=col;
            while(r<n-1 and c<m-1)
            {
                if(matrix[r][c]!=matrix[r+1][c+1])
                    return false;
                r++;
                c++;
            }
            col++;
        }
        while(row<n)
        {
            int r=row;
            int c=0;
            while(r<n-1 and c<m-1)
            {
                if(matrix[r][c]!=matrix[r+1][c+1]) return false;
                r++;
                c++;
            }
            row++;
        }
        return true;
    }
};

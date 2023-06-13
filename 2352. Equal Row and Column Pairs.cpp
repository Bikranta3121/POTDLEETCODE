class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
       map<vector<int>,int> ans;
       int count=0;
       for(int  i=0;i<grid.size();i++)
       {
        
               ans[grid[i]]++;
       
         
       } 
       for(int i=0;i<grid[0].size();i++)
       {
           vector<int> temp;
           for(int j=0;j<grid.size();j++)
           {
               temp.push_back(grid[j][i]);
           }
           if(ans.find(temp)!=ans.end()) count+=ans[temp];
       }
       return count;
    }
};

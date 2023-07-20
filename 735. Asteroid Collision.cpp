class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int i=0;i<asteroids.size();i++)
        {
           while(!ans.empty() and ans[ans.size()-1]>=0 and asteroids[i]<0 and abs(ans[ans.size()-1])<abs(asteroids[i]))
           {
             ans.pop_back();
           }
           if(!ans.empty() and ans[ans.size()-1]>=0 and asteroids[i]<0 and abs(ans[ans.size()-1])==abs(asteroids[i]))
           {
               ans.pop_back();
           }
           else if(!ans.empty() and ans[ans.size()-1]>=0 and asteroids[i]<0 and abs(ans[ans.size()-1])>abs(asteroids[i]))
           {
               continue;
           }
           else{
               ans.push_back(asteroids[i]);
           }
        }
        return ans;
    }
};

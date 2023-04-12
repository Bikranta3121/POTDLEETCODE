class Solution {
public:
    string simplifyPath(string path) {
        string ans="";
        ans.push_back('/');
        int n=path.size();
        int i=0;
        int flag=0;
        while(i<n)
        {
            if(ans[ans.size()-1]=='/' and path[i]=='/')
            {
              flag=1-flag;
              i++;
            }
            else if(path[i]=='.' and ans[ans.size()-1]!='/')
            {
             ans.push_back(path[i]);
             i++;
            }
            else if( i<n-2 and path[i]=='.' and path[i+1]=='.' and (path[i+2]=='.' || isalpha(path[i+2]) ))
            {
               while(i<n and path[i]!='/')
               {
                   ans.push_back(path[i]);
                   i++;
               }
            }
            else if(i<n-1 and path[i]=='.' and isalpha(path[i+1]))
            {
               while(i<n and path[i]!='/')
               {
                   ans.push_back(path[i]);
                   i++;
               } 
            }
            else if(i<n-1 and path[i]=='.' and path[i+1]=='.' and ans[ans.size()-1]=='/')
            {
                 ans.pop_back();
                while(!ans.empty() and ans[ans.size()-1]!='/')
                 ans.pop_back();
                if(ans.empty()) ans.push_back('/'); 
                i++;
            }
            else if(path[i]!='.')
            {
             ans.push_back(path[i]); 
             i++;
            }
            else
            {
                i++;
            }
        }
       
        while(ans.size()>1 and ans[ans.size()-1]=='/')
         ans.pop_back();
        return ans; 
    }
};

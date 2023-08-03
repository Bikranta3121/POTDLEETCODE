class Solution {
public:
vector<char> adj[8]={    
    {'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    void solve(int i,string &digits,vector<string> &res,string &s)
    {
        if(i>=digits.size())
        {
            res.push_back(s);
            return;
        }

        int num=(int)(digits[i]-'0')-2;
        cout<<num;
        for(char ch:adj[num])
        {
            s.push_back(ch);
            solve(i+1,digits,res,s);
            s.pop_back();
        } 
        return;
        

    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        string s;
        solve(0,digits,res,s);
        return res;
    }
};

class Solution {
public:
    string makeGood(string s) {
        int i=0;
        string ans;
        while(i<s.size())
        {
            if(i<s.size()-1 and (isupper(s[i]) xor isupper(s[i+1])) and (tolower(s[i])==tolower(s[i+1])))
            {
              s.erase(i,2);   
              i=0;
            }
            else
            {
                i+=1;
            }
        }
        return s;
    }
};

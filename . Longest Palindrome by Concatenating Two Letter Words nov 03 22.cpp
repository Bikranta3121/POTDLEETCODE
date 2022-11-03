class Solution {
public:
    int longestPalindrome(vector<string>& words) {
     map<pair<char,char>,int> m;
        int count=0;
     for(int i=0;i<words.size();i++)
     {
         if(m.find({words[i][0],words[i][1]})==m.end())
         {
             m[{words[i][0],words[i][1]}]=1;
             if(words[i][0]!=words[i][1])
              m[{words[i][1],words[i][0]}]=0;
         }
         else
         {
             m[{words[i][0],words[i][1]}]++;
         }
     }
        vector<int> even;
        vector<int> odd;
        
      for(int i=0;i<words.size();i++)
     {
         if(m.find({words[i][0],words[i][1]})!=m.end() and words[i][0]!=words[i][1])
         {
                     count+=2*min(m[{words[i][0],words[i][1]}], m[{words[i][1],words[i][0]}]);
             m.erase({words[i][0],words[i][1]});
             m.erase({words[i][1],words[i][0]});
         }
         else if(m.find({words[i][0],words[i][1]})!=m.end() and words[i][0]==words[i][1])
         {
          if(m[{words[i][0],words[i][1]}]%2==0)  even.push_back(m[{words[i][0],words[i][1]}]);
            else odd.push_back(m[{words[i][0],words[i][1]}]);
            m.erase({words[i][0],words[i][1]}); 
             
         }
     }
        if(!odd.empty()){sort(odd.begin(),odd.end());
        for(int i=0;i<odd.size();i++)
        {
            if(i==odd.size()-1) count+=odd[i];
            else count+=odd[i]-1;
        }
                        }
        for(int i=0;i<even.size();i++)
        {
            count+=even[i];
        }
       
        return (2*count);
        
        
    }
};

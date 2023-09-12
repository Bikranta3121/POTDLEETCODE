class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        map<int,int> mp;
        for(int i=0;i<s.size();i++)
        {
           freq[s[i]-'a']++;
        }
        unordered_set<int> st;
        for(int i=0;i<26;i++)
        {
            if(freq[i]) 
            { 
                st.insert(freq[i]);
                mp[freq[i]]++;
            }
        }
        int sum=0;
        for(auto itr:mp)
        {
            int n=itr.second;
            int x=itr.first-1;
          
               while(x>=0 and n>1)
               {
                   if(st.find(x)==st.end()) 
                   {
                       sum+=itr.first-x;
                       st.insert(x); 
                       n-=1;
                   }                   
                   x--;                   
               } 
               if(n>1)
                {
                       sum+=(n-1)*itr.first;
                }
             
        }
        return sum;
    }
};

class Solution {
public:
    string reverseVowels(string s) {
        stack<char> st;
        for(char ch:s)
        {
                        if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u' or ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U')
                st.push(ch);
        }
        
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u' or ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U')
            {
                ch=st.top();
                st.pop();
                s[i]=ch;
            }
        }
        return s;
    }
};

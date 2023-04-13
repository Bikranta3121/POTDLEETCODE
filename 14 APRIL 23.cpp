class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0;
        int j=0;
        int n=pushed.size();
        
        while(i<=n and j<n)
        {
            if(!st.empty() and st.top()==popped[j])
            {
                st.pop();
                j++;
            }
            else if(i==n) break;
            else
            {
                st.push(pushed[i]);
                i++;
            }
        }
        if(st.empty()) return true;
        return false;

    }
};

class Solution {
public:
    bool isvalid(int mid,int k,string &answerKey)
    {
        vector<int> freq(2,0);
        int n=answerKey.size();
        for(int i=0;i<mid;i++)
        {
            if(answerKey[i]=='F') freq[0]++;
            else freq[1]++;
        }
        if(min(freq[0],freq[1])<=k) return true;
        for(int i=1;i<n-mid+1;i++)
        {
            if(answerKey[i-1]=='F') freq[0]--;
            else freq[1]--;

            if(answerKey[i+mid-1]=='F') freq[0]++;
            else freq[1]++;
            
            if(min(freq[0],freq[1])<=k) return true;
        }
         return false;

    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int low=1;
        int high=answerKey.size();
        int ans=1;
        while(low<=high)
        {
            int mid=high-(high-low)/2;
            if(isvalid(mid,k,answerKey))
            {
                low=mid+1;
                ans=mid;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};

class Solution {
public:
        int minimizeMax(vector<int>& A, int p) {
        sort(A.begin(), A.end());
        int n = A.size(), left = 0, right = A[n - 1] - A[0];
        while (left < right) {
            int mid = (left + right) / 2, k = 0;
            int i=1;         
            while(i<A.size())
            {
              if(A[i]-A[i-1]<=mid)
              {
                 k++;
                 i++;
              }
              i++;
            }
            if (k >= p)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

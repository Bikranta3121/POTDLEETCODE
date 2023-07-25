class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=1;
        int h=arr.size()-2;
        while(l<=h)
        {
            int mid=h-(h-l)/2;
            if(arr[mid-1]<arr[mid] and arr[mid]>arr[mid+1])
            {
               return mid;
            }
            else if(arr[mid-1] <= arr[mid] and arr[mid]<=arr[mid+1])
            {
                l=mid+1;
            }
            else
            {
               h=mid-1;
            }
        }
        return -1;
    }
};

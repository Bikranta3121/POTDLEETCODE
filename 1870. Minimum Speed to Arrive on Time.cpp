class Solution {
public:
    bool chk(int mid,vector<int> &dist,double hour)
    {
        double sum=0;
        for(int i=0;i<dist.size()-1;i++)
        {
            int x=dist[i]/mid;
            sum=sum+x;
            if(dist[i]%mid!=0) sum=sum+1.0;
            if(sum>hour) return false;
        }
        sum+=(double)dist.back()/mid;
        
        if(sum>hour) return false;
        return true;
        
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1;
        int h=100000000;
        int ans=-1;
        while(l<=h)
        {
            int mid=h-(h-l)/2;
            if(chk(mid,dist,hour))
            {
                ans=mid;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;

    }
};

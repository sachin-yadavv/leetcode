class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size()==0 || duration==0) return 0;
        int cnt=0;
        int n = timeSeries.size();
        for(int i=1;i<n;i++){
            cnt+=min(duration , timeSeries[i]-timeSeries[i-1]) ;
        }
        return duration+ cnt;
    }
};
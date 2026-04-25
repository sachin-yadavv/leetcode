class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int idx=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]) idx=i;
        }
        long long lsum=0;
        for(int i=0;i<idx;i++)
        lsum+=nums[i];
         long long  rsum=0;
        for(int i=idx+1;i<n;i++)
        rsum+=nums[i];

        if(rsum==lsum) return -1;
        else if(rsum>lsum) return 1;

        return 0;
    }
};
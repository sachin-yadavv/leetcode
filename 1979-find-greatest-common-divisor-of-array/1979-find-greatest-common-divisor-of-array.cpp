class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
        }
        for(int i=mn;i>=1;i--){
            if((mn%i==0) &&  (mx%i==0)) return i;
        }
        return 1;
    }
};
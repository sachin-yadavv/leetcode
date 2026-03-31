class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n ,0);
        int l=0;
        int r=n;
        int i=0;
        while(n>0){
            ans[i++]=nums[l++];
            ans[i++]=nums[r++];
            n--;
        }
        return ans;
    }
};
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=0;
        int a=0;
        int b = nums.size()-1;

        while(a<b){
        maxi=max(maxi,nums[a]+nums[b]);
        a++;
        b--;
    }
    return maxi;
        
    }
};
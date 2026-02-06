class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int left=nums[0];
        int maxi=nums[0];
        int ans=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
        
            maxi=max(maxi,nums[i]);

            if(nums[i]<left){
                left=maxi;
                ans=i;
            }
        }

        return ans+1;
    }
};
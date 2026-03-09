class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int a = 0, b = 0;
        int n = nums.size();
        int maxi = 0;

        while(b < n){
            int diff = nums[b] - nums[a];

            if(diff == 1){
                maxi = max(maxi, b - a + 1);
                b++;
            }
            else if(diff < 1){
                b++;
            }
            else{
                a++;
            }
        }

        return maxi;
    }
};
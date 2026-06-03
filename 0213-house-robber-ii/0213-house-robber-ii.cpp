class Solution {
public:
  int solve(vector<int>&nums){
    int n = nums.size();
        vector<int>dp(n,-1);
          dp[0]=nums[0];

          for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take=nums[i]+dp[i-2];
            int notTake = dp[i-1];

            dp[i]=max(take,notTake);
          }
         
         return  dp[n-1];
  }

    int rob(vector<int>& nums) {
            int n = nums.size();

    if (n == 0) return 0;

    
    if (n == 1) return nums[0];

    vector<int> arr1, arr2;
    for (int i = 0; i < n; i++) {
        if (i != 0) arr1.push_back(nums[i]);
        if (i != n - 1) arr2.push_back(nums[i]);
    }

    
    long long int ans1 = solve(arr1);
    long long int ans2 = solve(arr2);
    return max(ans1, ans2);
    }
};
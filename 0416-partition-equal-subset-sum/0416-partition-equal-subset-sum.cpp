class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int totalSum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) 
            totalSum += arr[i];
        
        if (totalSum % 2 != 0) 
            return false;        

        int targetSum = totalSum / 2;

        vector<vector<bool>> dp(n, vector<bool>(targetSum + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        if (arr[0] <= targetSum) {
            dp[0][arr[0]] = true;
        }

        for (int index = 1; index < n; index++) {
            for (int target = 1; target <= targetSum; target++) {
                bool notTaken = dp[index - 1][target];
                bool taken = false;
                if (arr[index] <= target) {
                    taken = dp[index - 1][target - arr[index]];
                }
                dp[index][target] = notTaken || taken;
            }
        }

        return dp[n - 1][targetSum];
    }
};
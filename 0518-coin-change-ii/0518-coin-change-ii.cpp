class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0)
                dp[0][t] = 1;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int t = 0; t <= amount; t++) {
                long notTake = dp[ind - 1][t];

                long take = 0;
                if (coins[ind] <= t)
                    take = dp[ind][t - coins[ind]];

                dp[ind][t] = take + notTake;
            }
        }

        return dp[n - 1][amount];
    }
};
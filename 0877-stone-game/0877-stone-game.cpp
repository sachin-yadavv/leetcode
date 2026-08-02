class Solution {
public:
int dp[501][501];
int solve(int i, int j, vector<int>& nums) {

        if (i > j)
            return 0;

        if (i == j)
            return nums[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        int takeLeft = nums[i] + min(
            solve(i + 2, j, nums),
            solve(i + 1, j - 1, nums)
        );

        int takeRight = nums[j] + min(
            solve(i, j - 2, nums),
            solve(i + 1, j - 1, nums)
        );

        return dp[i][j] = max(takeLeft, takeRight);
    }
    bool stoneGame(vector<int>& nums) {

        memset(dp, -1, sizeof(dp));

        int total = 0;
        for (int x : nums)
            total += x;

        int player1 = solve(0, nums.size() - 1, nums);

        int player2 = total - player1;

        return player1 >= player2;
    }
};
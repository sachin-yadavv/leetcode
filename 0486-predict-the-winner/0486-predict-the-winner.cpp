// class Solution {
// public:
//     bool PredictTheWinner(vector<int>& nums) {
//         int n = nums.size();

//         vector<vector<long long>> dp(n, vector<long long>(n, 0));

//         // Base case: one element
//         for (int i = 0; i < n; i++)
//             dp[i][i] = nums[i];

//         // Length = 2 to n
//         for (int len = 2; len <= n; len++) {

//             for (int i = 0; i + len - 1 < n; i++) {

//                 int j = i + len - 1;

//                 long long a = (i + 2 <= j) ? dp[i + 2][j] : 0;
//                 long long b = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
//                 long long c = (i <= j - 2) ? dp[i][j - 2] : 0;

//                 long long takeLeft = nums[i] + min(a, b);
//                 long long takeRight = nums[j] + min(c, b);

//                 dp[i][j] = max(takeLeft, takeRight);
//             }
//         }

//         long long total = 0;
//         for (int x : nums)
//             total += x;

//         return dp[0][n - 1] >= total - dp[0][n - 1];
//     }
// };


class Solution {
public:
    int dp[21][21];

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

    bool predictTheWinner(vector<int>& nums) {

        memset(dp, -1, sizeof(dp));

        int total = 0;
        for (int x : nums)
            total += x;

        int player1 = solve(0, nums.size() - 1, nums);

        int player2 = total - player1;

        return player1 >= player2;
    }
};
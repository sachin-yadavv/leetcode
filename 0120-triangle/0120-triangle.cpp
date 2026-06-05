class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1)); 
        // tabulation from n-1 to 0 
        // recursion from 0 to n-1
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];                  // base case
        }
            for(int i=n-2;i>=0;i--){
                for(int j=i;j>=0;j--){
                    int d=triangle[i][j]+dp[i+1][j];
                    int dg=triangle[i][j]+dp[i+1][j+1];

                    dp[i][j]=min(d,dg);
                }
            }
            return dp[0][0];
        }
};
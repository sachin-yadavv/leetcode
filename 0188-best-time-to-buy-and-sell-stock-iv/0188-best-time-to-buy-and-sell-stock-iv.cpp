class Solution {
public:
    int maxProfit(int k , vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int tr=2*k-1;tr>=0;tr--){               
             int profit=0;
                        if(tr%2==0){
                      profit=max(-prices[ind]+dp[ind+1][tr+1],dp[ind+1][tr]);
                        }
               else profit=max(prices[ind]+dp[ind+1][tr+1],dp[ind+1][tr]);
               dp[ind][tr]=profit;
                
            }
        }

        return dp[0][0];
    }
};
class Solution {
public:
int func(int ind , int buy , vector<int>& prices , int n ,vector<vector<vector<int>>> & dp,int cap){
    if(ind==n) return 0;
    if(cap==0) return 0;
    if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
    int profit=0;
    if(buy){
        profit=max(-prices[ind]+func(ind+1,0,prices,n,dp,cap),func(ind+1,1,prices,n,dp,cap));
    }
    else profit=max(prices[ind]+func(ind+1,1,prices,n,dp,cap-1),func(ind+1,0,prices,n,dp,cap));

    return dp[ind][buy][cap]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return func(0,1,prices,n,dp,2);
    }
};
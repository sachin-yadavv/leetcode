class Solution {
public:
int func(int ind,int T,vector<int>&a, vector<vector<int>> &dp){
    if(ind==0){
        if(T%a[ind]==0) return T/a[ind];
        else return 1e9;
    }
    if(dp[ind][T]!=-1) return dp[ind][T];
    int notake= 0+func(ind-1,T,a,dp);
    int take=1e9;
    if(a[ind]<=T) take = 1+func(ind,T-a[ind],a,dp);

    return dp[ind][T]= min(take,notake);
}
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans =  func(n-1,amount,coins,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};
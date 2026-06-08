class Solution {
public:

       int coinChange(vector<int>& a, int amount) {
        int n = a.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int t=0;t<=amount;t++){
             if(t%a[0]==0) dp[0][t]=t/a[0];
            else dp[0][t]=1e9;
        }
        for(int ind=1;ind<n;ind++){
            for(int t=0;t<=amount;t++){
                  int notake= 0+dp[ind-1][t];
                    int take=1e9;
                if(a[ind]<=t) take = 1+dp[ind][t-a[ind]];

                 dp[ind][t]= min(take,notake);
            }
        }
        
        int ans =  dp[n-1][amount];
        if(ans>=1e9) return -1;
        return ans;
    }
};
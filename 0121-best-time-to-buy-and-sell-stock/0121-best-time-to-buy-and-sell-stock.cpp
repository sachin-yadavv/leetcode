class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit=0;
        int minimum = prices[0];
        for(int i =1; i<n;i++){
              profit=max(profit,prices[i]-minimum);  
              minimum = min(minimum,prices[i]);  
        }
        
        if(profit<=0) return 0;
        else return profit;
        
    }
};
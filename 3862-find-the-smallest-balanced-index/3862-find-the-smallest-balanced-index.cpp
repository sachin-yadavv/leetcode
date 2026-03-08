class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        vector<long long > sum(n,0);
        vector<long long > pro(n,1);
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+nums[i-1];
        }
        
         long long prod = 1;

        for(int i=n-2;i>=0;i--){

            if(prod > 1e18 / nums[i+1])
                prod = 1e18;
            else
                prod *= nums[i+1];

            pro[i] = prod;
        }
    
        for(int i=0;i<n;i++){
            if(sum[i]==pro[i]) return i;
        }
        return -1;
    }
};
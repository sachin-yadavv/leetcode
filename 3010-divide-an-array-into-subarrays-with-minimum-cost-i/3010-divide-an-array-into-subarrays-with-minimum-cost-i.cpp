class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        if(n<=3){
            for(int i=0;i<n;i++)
            sum+=nums[i];

            return sum;
        }
        int min1=51;
        int min2=51;
        for(int i=1;i<n;i++){
            if(nums[i]<min1) {
                min2=min1;
                min1=nums[i];      
        }
        else if(nums[i] < min2 ) 
            min2 = nums[i];
    }
    return min1+min2+nums[0];
    }
};
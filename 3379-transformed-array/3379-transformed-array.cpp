class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                int ind=nums[i]%n;
                result[i]=nums[(i+ind)%n];

            }
            else if(nums[i]<0){
               int ind=nums[i]%n;
               result[i]=nums[(n+i+ind)%n];
            }
            else 
            result[i]=nums[i];
        }



        return result;
    }
};
class Solution {
public:
    float func(vector<int>& nums , int index){
        int n =nums.size();
        float sum=0;
        for(int i=index+1;i<n;i++){
          sum+=nums[i];
        }
        return sum/(n-index-1);
    }
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
          if(nums[i]>func(nums,i)) cnt++;
        }
        return cnt;
    }
};
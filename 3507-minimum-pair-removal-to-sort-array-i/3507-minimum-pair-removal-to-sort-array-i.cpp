class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;

        while(true){
            bool flag = true;
            for(int i=1;i<nums.size();i++){
                if(nums[i] < nums[i-1]){
                    flag = false;
                    break;
                }
            }
            if(flag) break;

            int mini = INT_MAX;
            int ind = -1;

            for(int j=0;j<nums.size()-1;j++){
                int sum = nums[j] + nums[j+1];
                if(sum < mini){
                    mini = sum;
                    ind = j;
                }
            }

            nums[ind] = nums[ind] + nums[ind+1];
            nums.erase(nums.begin() + ind + 1);
            cnt++;
        }

        return cnt;
    }
};
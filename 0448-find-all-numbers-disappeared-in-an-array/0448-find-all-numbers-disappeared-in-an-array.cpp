class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
     vector<int> miss;

        for(int i = 0; i < nums.size(); i++){
            int idx = abs(nums[i]) - 1;

            if(nums[idx] < 0) continue;
            else{
                nums[idx] *= -1;
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)
                miss.push_back(i+1);
        }

        return miss;
    
    }
};
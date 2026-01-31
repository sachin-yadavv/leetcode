class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n =nums.size();
        vector<int> pos;
        for(int i=0;i<n;i++){
            if(nums[i]>=0)
            pos.push_back(nums[i]);
        }
        if(pos.size()==0) return nums;
        int m=pos.size();
        k=k%m;
        reverse(pos.begin(), pos.begin() + k);
        reverse(pos.begin() + k, pos.end());
        reverse(pos.begin(), pos.end());

        int l=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=0)
            nums[i]=pos[l++];
        }

        return nums;

    }
};
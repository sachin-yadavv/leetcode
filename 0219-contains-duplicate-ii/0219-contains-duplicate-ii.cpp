class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        for(auto it: mpp){
            vector<int> v = it.second;
            int size=v.size();
            for(int i=1;i<size;i++){
                if(abs(v[i]-v[i-1])<=k) return true;
            }
        }
        return false;
    }
};
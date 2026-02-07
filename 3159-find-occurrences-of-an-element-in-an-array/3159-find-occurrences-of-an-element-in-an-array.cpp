class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int, vector<int>> mpp;
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m,-1);
        for(int i=0;i<n;i++){
            if(nums[i]==x){
            mpp[nums[i]].push_back(i);
            }
        }
        for(int i=0;i<m;i++){
            if(queries[i]<=mpp[x].size()){
                ans[i]=mpp[x][queries[i]-1];
            }
        }

        return ans;
    }
};
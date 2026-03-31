class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        
        int dup=-1;
        int sum=0;
        map<int,int>mpp;
        for(auto it: nums){
            if(mpp[it]==1) dup=it;
            mpp[it]++;
            sum+=it;
          
        }
        int miss=n*(n+1)/2-(sum-dup);
        return {dup,miss};

    }
};
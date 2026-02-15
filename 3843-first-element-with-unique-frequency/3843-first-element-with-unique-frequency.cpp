class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int,int> mpp;
        map<int,int> freqCount;
        for( auto it : nums){
            mpp[it]++;
        }
        for( auto it : mpp){
            freqCount[it.second]++;
        }
        for(auto x : nums){
            if(freqCount[mpp[x]]==1) return x;
        }
        return -1;
    }
};
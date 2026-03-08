class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int mini=INT_MAX;
        int ans=-1;
        int n = capacity.size();
        for(int i=0;i<n;i++){
            if(capacity[i]>=itemSize && capacity[i]<mini ){
               ans=i;
               mini=capacity[i];
            }
        }
        return ans;
        
    }
};
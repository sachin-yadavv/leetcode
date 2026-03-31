class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>ans=nums;
        sort(ans.begin(),ans.end());
        map<int,int> mpp;
        int n = ans.size();
        for(int i=0;i<n;i++){
            if(mpp.find(ans[i]) == mpp.end()){
                mpp[ans[i]]=i;
            }
        }
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
          res[i]=mpp[nums[i]];
        }
       return res;
    }
};
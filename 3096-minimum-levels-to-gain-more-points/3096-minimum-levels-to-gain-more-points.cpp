class Solution {
public:
    int minimumLevels(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int>suff(n);
        if(nums[0]==1) pre[0]=1;
        if(nums[0]==0) pre[0]=-1;
        if(nums[n-1]==1) suff[n-1]=1;
        if(nums[n-1]==0) suff[n-1]=-1;

        // for prefix
        for(int i=1;i<n;i++){
            if(nums[i]==1)
            pre[i]=pre[i-1]+1;
            else 
             pre[i]=pre[i-1]-1;
        }

        // for suffix
        for(int i=n-2;i>=0;i--){
            if(nums[i]==1)
            suff[i]=suff[i+1]+1;
            else 
             suff[i]=suff[i+1]-1;
        }

        for(int i=0;i<n-1;i++){
           if(pre[i]>suff[i+1]) return i+1;
        }
      return -1;
    }
};
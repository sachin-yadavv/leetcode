class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if(n<1) return ans;
        int start=nums[0];
        
    for(int i=0;i<n;i++){

        if(i == n-1 ||nums[i]+1!=nums[i+1]){
            int end=nums[i];
            if(start!=end) ans.push_back(to_string(start)+"->"+to_string(end));

            else ans.push_back(to_string(start));

             if(i != n-1)
            start=nums[i+1];
            }
            
        }
        return ans;
    
    }
};
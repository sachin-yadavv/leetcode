class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long>st;
        int n = nums.size();
        st.push(nums[0]);
        for(int i=1;i<n;i++){
            long long  a=nums[i];
           
            while (!st.empty() && a==st.top()){
            st.pop();
            a=2*a;
            // st.push(a);
           }
           
         st.push(a);
        }
        vector<long long > ans;
        while(!st.empty()){
            long long top=st.top();
            ans.push_back(top);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
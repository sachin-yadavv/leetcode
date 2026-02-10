class Solution {
public:
    
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            set<int> s; // for even
            set<int> t;  // for odd

          if(nums[i]%2==0) s.insert(nums[i]);
          else t.insert(nums[i]);

          for(int j=i+1;j<n;j++){

            if(nums[j]%2==0) s.insert(nums[j]);
            else t.insert(nums[j]);

            if(s.size()==t.size())
            maxi = max(maxi, j - i + 1); 
           
           }

        }

        return maxi;

    }
};
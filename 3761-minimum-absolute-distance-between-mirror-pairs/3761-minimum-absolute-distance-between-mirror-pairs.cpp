class Solution {
public:
    int reverseNum(int x) {
        int ans = 0;
        while (x > 0) {
            ans = ans * 10 + (x % 10);
            x /= 10;
        }
        return ans;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {

            if (mpp.find(nums[i]) != mpp.end()) {
                ans = min(ans, i - mpp[nums[i]]);
            }

            int rev = reverseNum(nums[i]);

            // 🔥 always update to latest index
            mpp[rev] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int l = 0; l < n; l++) {

            unordered_map<int, int> freq;
            map<int, int> cntFreq;

            for (int r = l; r < n; r++) {

                int x = nums[r];

                // old frequency
                int old = freq[x];

                // remove old frequency
                if (old > 0) {
                    cntFreq[old]--;
                    if (cntFreq[old] == 0)
                        cntFreq.erase(old);
                }

                // increase frequency
                freq[x]++;
                cntFreq[old + 1]++;

                // only one distinct value
                if (freq.size() == 1) {
                    ans = max(ans, r - l + 1);
                    continue;
                }

                // exactly two different frequencies
                if (cntFreq.size() == 2) {

                    auto it = cntFreq.begin();

                    int f1 = it->first;
                    ++it;
                    int f2 = it->first;

                    if (f2 == 2 * f1)
                        ans = max(ans, r - l + 1);
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    long long safe_lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long maxScore(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 1LL * nums[0] * nums[0];

        vector<int> preG(n), sufG(n);
        vector<long long> preL(n), sufL(n);

        // prefix
        preG[0] = nums[0];
        preL[0] = nums[0];

        for(int i = 1; i < n; i++) {
            preG[i] = gcd(preG[i-1], nums[i]);
            preL[i] = safe_lcm(preL[i-1], nums[i]);
        }

        // suffix
        sufG[n-1] = nums[n-1];
        sufL[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--) {
            sufG[i] = gcd(sufG[i+1], nums[i]);
            sufL[i] = safe_lcm(sufL[i+1], nums[i]);
        }

        long long ans = 1LL * preG[n-1] * preL[n-1]; // 🔥 include full array

        for(int i = 0; i < n; i++) {
            int g;
            long long l;

            if(i == 0) {
                g = sufG[1];
                l = sufL[1];
            }
            else if(i == n-1) {
                g = preG[n-2];
                l = preL[n-2];
            }
            else {
                g = gcd(preG[i-1], sufG[i+1]);
                l = safe_lcm(preL[i-1], sufL[i+1]);
            }

            ans = max(ans, 1LL * g * l);
        }

        return ans;
    }
};
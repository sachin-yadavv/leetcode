class Solution {
public:
    static const int MOD = 1e9 + 7;
    static const int MX = 100001;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        static vector<long long> pow10 = []() {
            vector<long long> p(MX);
            p[0] = 1;
            for (int i = 1; i < MX; i++)
                p[i] = p[i - 1] * 10 % MOD;
            return p;
        }();

        int n = s.size();

        vector<int> sumD(n + 1), cnt(n + 1);
        vector<long long> pref(n + 1);

        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';

            sumD[i] = sumD[i - 1] + d;
            cnt[i] = cnt[i - 1] + (d != 0);

            if (d)
                pref[i] = (pref[i - 1] * 10 + d) % MOD;
            else
                pref[i] = pref[i - 1];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int len = cnt[r + 1] - cnt[l];
            int sum = sumD[r + 1] - sumD[l];

            long long x = (pref[r + 1] - pref[l] * pow10[len] % MOD + MOD) % MOD;

            ans.push_back(x * sum % MOD);
        }

        return ans;
    }
};
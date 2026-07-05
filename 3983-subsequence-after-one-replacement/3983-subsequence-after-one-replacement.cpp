class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        if (n > m) return false;

        vector<int> pref(n, -1), suff(n, -1);

        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && t[j] != s[i]) j++;
            if (j == m) break;
            pref[i] = j;
            j++;
        }

        // Already a subsequence
        if (pref[n - 1] != -1) return true;

        // Latest matches
        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (j >= 0 && t[j] != s[i]) j--;
            if (j < 0) break;
            suff[i] = j;
            j--;
        }

        // Try replacing each character
        for (int i = 0; i < n; i++) {
            int left = (i == 0) ? -1 : pref[i - 1];
            int right = (i == n - 1) ? m : suff[i + 1];

            if (left != -1 || i == 0) {
                if (right != -1 || i == n - 1) {
                    if (left + 1 < right)
                        return true;
                }
            }
        }

        return false;
    }
};
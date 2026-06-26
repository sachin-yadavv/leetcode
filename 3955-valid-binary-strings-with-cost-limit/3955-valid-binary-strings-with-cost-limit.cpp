class Solution {
public:
vector<string> ans;

    void solve(int idx, int n, int k, int cost, string &s) {
        if (idx == n) {
            ans.push_back(s);
            return;
        }

        // Place 0
        s.push_back('0');
        solve(idx + 1, n, k, cost, s);
        s.pop_back();

        // Place 1
        if ((idx == 0 || s.back() == '0') && cost + idx <= k) {
            s.push_back('1');
            solve(idx + 1, n, k, cost + idx, s);
            s.pop_back();
        }
    }
    
    vector<string> generateValidStrings(int n, int k) {
        string s = "";
        solve(0, n, k, 0, s);
        return ans;
    }
};
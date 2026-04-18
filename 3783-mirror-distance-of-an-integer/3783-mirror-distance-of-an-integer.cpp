class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x > 0) {
            ans = ans * 10 + (x % 10);
            x /= 10;
        }
        return ans;
    }
    int mirrorDistance(int n) {
        int rev=reverse(n);
        return abs(n-rev);
    }
};
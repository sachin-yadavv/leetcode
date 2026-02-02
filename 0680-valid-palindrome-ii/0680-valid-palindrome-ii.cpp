class Solution {
public:
    bool isPal(string &s, int l, int r){
        while(l < r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int low = 0, high = s.size() - 1;

        while(low < high){
            if(s[low] == s[high]){
                low++;
                high--;
            }
            else{
                return isPal(s, low+1, high) || isPal(s, low, high-1);
            }
        }
        return true;
    }
};

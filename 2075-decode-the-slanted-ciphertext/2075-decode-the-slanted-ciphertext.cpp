class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int col =  n/ rows;

        string ans;
        for (int i = 0; i < col; i++) {
            for (int j = i; j < n; j += (col + 1)) {
                ans += encodedText[j];
            }
        }

        //Remove spaces put at the end
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        
        return ans;
    }
};
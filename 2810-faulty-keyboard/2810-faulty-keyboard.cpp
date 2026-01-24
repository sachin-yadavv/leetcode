class Solution {
public:
    string finalString(string s) {
        int n = s.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='i' && ans.size()>0){
                reverse(ans.begin(),ans.end());
            }
            else 
            ans.push_back(s[i]);
        }
        return ans;
    }
};
class Solution {
public:
    int furthestDistanceFromOrigin(string s) {
        int n = s.size();
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L') cnt1++;

            else if(s[i]=='R') cnt2++;
        }
        // if cnt1 > cnt2 _ = L
        // else _ = R
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L') ans--;
            else if (s[i]=='R') ans ++;

            else {
                if(cnt1>cnt2) ans--;
                else ans++;
            }
        }
        return  abs(ans);

    }
};
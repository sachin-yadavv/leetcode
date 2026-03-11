class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2){
            string temp;
            int n = s.size();
            for(int i=0;i<n-1;i++){
               temp.push_back((s[i]+s[i+1])%10);
            }
            s=temp;
        }
        if(s[0]==s[1]) return true;
    
     return false;   
    }
};
class Solution {
public:
    bool validDigit(int n, int x) {
        string num=to_string(n);
        int a=num.size();
        if(num[0]-'0'==x) return false;
        for(int i=1;i<a;i++){
            if(num[i]-'0'==x) return true;
        }
        return false;

    }
};
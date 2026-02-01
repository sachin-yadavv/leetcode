class Solution {
public:
    int passThePillow(int n, int time) {
        if(time<n) return time+1;

        int cyc=time/(n-1);
        if(cyc%2==0) return 1+time%(n-1);
        return n-time%(n-1);
    }
};
class Solution {
public:
    bool checkGoodInteger(int n) {
        long long sum1=0;
        long long sum2=0;
        while(n>0){
            int digit=n%10;
            sum1+=digit;
            sum2+=digit*digit;
            n=n/10;
        }
        return sum2-sum1>=50;
    }
};
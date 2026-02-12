class Solution {
public:
    int strStr(string h, string n) {

        int n1 = h.size();
        int n2 = n.size();

        if(n2 == 0) return 0;

        int i = 0;

        while(i <= n1 - n2){

            int a = i;
            int b = 0;

            while(a < n1 && b < n2 && h[a] == n[b]){
                a++;
                b++;
            }

            if(b == n2) return i;

            i++;   
        }
        return -1;
    }
};

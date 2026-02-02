class Solution {
public:
    string solveEquation(string s) {
        int coeff = 0, constant = 0;

        int side = 1;   
        int sign = 1;

        int i = 0, n = s.size();

        while(i < n) {

            if(s[i] == '+') {
                sign = 1;
                i++;
            }
            else if(s[i] == '-') {
                sign = -1;
                i++;
            }
            else if(s[i] == '=') {
                side = -1;   
                sign = 1;    
                i++;
            }
            else {
                int num = 0;
                bool hasNum = false;

                while(i<n && isdigit(s[i])) {
                    num = num*10 + (s[i]-'0');
                    i++;
                    hasNum = true;
                }

                if(i<n && s[i]=='x') {
                    coeff += side * sign * (hasNum ? num : 1);
                    i++;
                }
                else {
                    constant += side * sign * num;
                }
            }
        }

        if(coeff == 0 && constant == 0) return "Infinite solutions";
        if(coeff == 0) return "No solution";

        return "x=" + to_string(-constant / coeff);
    }
};

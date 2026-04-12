class Solution {
public:
    bool func(double a , double b , double c){
        if(a+b>c && b+c >a && a+c>b) return true;
        return false;
    }
    vector<double> internalAngles(vector<int>& sides) {
        int n = sides.size();
        vector<double> ans(n);
        double a = sides[0];
        double b= sides[1];
        double c = sides[2];
        if(func(a,b,c)){
           double A = acos((b*b + c*c - a*a) / (2*b*c));
           double B = acos((a*a + c*c - b*b) / (2*a*c));
           double C = acos((a*a + b*b - c*c) / (2*a*b));

            // Convert radians to degrees
            A = A * 180.0 / M_PI;
            B = B * 180.0 / M_PI;
            C = C * 180.0 / M_PI;
            ans[0]=A;
            ans[1]=B;
            ans[2]=C;
            sort(ans.begin(),ans.end());
            return ans;
        }
        return {};
    }
};
class Solution {
public:

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> suff(n,0);
        vector<int> pref(n,0);
        int sum=0;
        pref[0]=height[0];
        for(int i=1;i<n;i++){
            pref[i]=max(pref[i-1] , height[i]);
        }

        suff[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=max(suff[i+1] , height[i]);
        }
        for(int i=0;i<n;i++){
            int leftmax=pref[i];
            int rightmax=suff[i];
            if(height[i]<leftmax && height[i]<rightmax)
            sum+=min(leftmax , rightmax)-height[i];
        }
        return sum;
    }
};
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m =mat[0].size();
        int maxi=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                cnt+=mat[i][j];
            }
            if(cnt>maxi){
                maxi=cnt;
                ans=i;
            }
        }
        return {ans,maxi};
    }
};
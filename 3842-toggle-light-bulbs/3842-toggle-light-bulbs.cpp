class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int,int> mpp;
        int n = bulbs.size();
        for(int i=0;i<n;i++){
            int bul=bulbs[i];
            if(mpp.count(bul)) mpp.erase(bul);
            else mpp[bul]++;
        }
        vector<int> ans;
        for(auto it : mpp){
           ans.push_back(it.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
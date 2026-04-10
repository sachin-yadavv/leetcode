class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int mini = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]].push_back(i);

            if(mp[nums[i]].size() >= 3){
                
                int sz = mp[nums[i]].size();
               // check last 3 consecutive
                int i1 = mp[nums[i]][sz-3];
                int i2 = mp[nums[i]][sz-2];
                int i3 = mp[nums[i]][sz-1];
                int dis= abs(i1-i2) + abs(i3-i2)+abs(i1-i3);
                mini = min(mini, dis);
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};
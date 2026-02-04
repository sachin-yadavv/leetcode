class Solution {
public:

    static bool cmp(pair<int,int>& a, pair<int,int>& b){
    return a.first < b.first;
}
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans;
        vector<pair<int,int>> arr;

        for(int i=0;i<n;i++){
            arr.push_back({intervals[i][0], i});
        }

        sort(arr.begin(),arr.end(),cmp); // using comparator 

        for(int i=0;i<n;i++){
           int low=0;
           int high=n-1;
           int ind=-1;
           int end=intervals[i][1];
           while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid].first>=end){
               ind=arr[mid].second;
               high=mid-1;
            }
              else low=mid+1;
           }
           ans.push_back(ind);
        }
        return ans;
    }
};
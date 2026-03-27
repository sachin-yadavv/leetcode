class Solution {
public:
vector<int> func1(vector<int>& heights , vector<int> & pse){
    int n = heights.size();
    stack<int> st;
    for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
      return pse;
}
vector<int> func2(vector<int>& heights , vector<int> & nse){
    int n = heights.size();
    stack<int> st;
    for (int i = n-1; i >=0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
      return nse;
}

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n);
        vector<int> pse(n);
        pse = func1(heights , pse );
        nse= func2(heights , nse );

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, heights[i] * (nse[i] - pse[i]-1));
        }

        return maxi;
    }
    
};
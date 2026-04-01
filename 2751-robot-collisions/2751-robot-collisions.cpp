class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<int> idx(n);
        for(int i = 0; i < n; i++) idx[i] = i;
        
         auto lambda = [&](int i, int j) {
            return positions[i] < positions[j];
        };

        sort(begin(idx), end(idx), lambda);

        stack<int> st; 

        for(int id : idx) {
            if(directions[id] == 'R') {
                st.push(id);
            } 
            else {
                //  moving left
                while(!st.empty() && healths[id] > 0) {
                    int j = st.top();
                    st.pop();  

                    if(healths[j] < healths[id]) {
                        // st.pop();
                        healths[j]=0;   // right dies 
                        healths[id]--;   // left  loses 1
                    } 
                    else if(healths[j] > healths[id]) {
                        healths[j]--;    // right survives
                        healths[id] = 0; // left dies
                        st.push(j);
                    } 
                    else {
                        // st.pop();
                        healths[j]=0;        // both die
                        healths[id] = 0;
                    }
                }
            }
        }

      
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> st;  

        for(int i=0; i < n; i++) {

            if(asteroids[i] > 0) 
                st.push_back(asteroids[i]);

            else {
                
                /* Until the right moving asteroids are 
                smaller in size */ 
                while(!st.empty() && st.back() > 0 && 
                      st.back() < abs(asteroids[i])) {
                    
                    // Destroy 
                    st.pop_back();
                }
                
                /* If there  of same size */
                if(!st.empty() && 
                    st.back() == abs(asteroids[i])) {
                    
                    // Destroy both 
                    st.pop_back();
                }
                
                /* if no left moving asteroid, right moving 
                will not be destroyed */
                else if(st.empty() ||
                        st.back() < 0){

                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};
class Solution {
public:

 vector<int> findNSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> nse(n);
        
        stack<int> st;
        
        for(int i = n - 1; i >= 0; i--) {
            
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            nse[i] = !st.empty() ? st.top() : n;

            st.push(i);
        }
        
        return nse;
    }
    

    vector<int> findPSEE(vector<int> &arr) {

        int n = arr.size();

        vector<int> psee(n);

        stack<int> st;
        

        for(int i=0; i < n; i++) {
           
            while(!st.empty() && arr[st.top()] > arr[i]){ // remember we are not taking>= to handle the edge case 
                st.pop();
            }
            
            psee[i] = !st.empty() ? st.top() : -1;
            

            st.push(i);
        }
        
 
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = 
            findNSE(arr);
        
        vector<int> psee =
            findPSEE(arr);
        
        int n = arr.size();
        
        int mod = 1e9 + 7; 

        int sum = 0;

        for(int i=0; i < n; i++) {
            
            int left = i - psee[i];

            int right = nse[i] - i;

            int val = (left*right*1LL*arr[i]*1LL) % mod;

            sum = (sum + val) % mod;
        }

        return sum;
    }
};
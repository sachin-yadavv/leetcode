class Solution {
public:

    vector<int> findNSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSEE(vector<int> &arr) {
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    long long funcMin(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        long long sum = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;

            sum += left * right * arr[i];
        }
        return sum;
    }

    vector<int> findNGEE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ngee(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            ngee[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ngee;
    }

    vector<int> findPGE(vector<int> &arr) {
        int n = arr.size();
        vector<int> pge(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }

    long long funcMax(vector<int>& arr) {
        vector<int> ngee = findNGEE(arr);
        vector<int> pge = findPGE(arr);

        long long sum = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = ngee[i] - i;

            sum += left * right * arr[i];
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return funcMax(nums) - funcMin(nums);
    }
};
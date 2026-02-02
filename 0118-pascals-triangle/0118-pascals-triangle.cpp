
    // vector<int> func(int row){
    //     long long ans=1;
    //     vector<int> rowAns;
    //     rowAns.push_back(1);
    //     for(int col=1;col<row;col++){
    //         ans=ans*(row-col);
    //         ans=ans/col;
    //         rowAns.push_back(ans);
    //     }
    //     return rowAns;

    // }
    class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            long long val = 1;   // first value always 1

            for (int j = 0; j <= i; j++) {
                row.push_back(val);
                val = val * (i - j) / (j + 1);  // nCr formula
            }

            res.push_back(row);
        }

        return res;
    }
};

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans=letters[0];
        int n=letters.size();
        int high=n-1;
        int low=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(letters[mid]-target >0){
            ans=letters[mid];
            high=mid-1;
            }
            else 
            low=mid+1;

        }

        return ans;
    }
};
class Solution {
public:
    string removeDuplicateLetters(string s) {

        vector<int> freq(26,0);
        vector<bool> vis(26,false);

        for(char c : s)
            freq[c-'a']++;

        string st="";

        for(char it : s){

            freq[it-'a']--;

            if(vis[it-'a']) 
                continue;

            while(!st.empty() && st.back()>it && freq[st.back()-'a']>0){
                vis[st.back()-'a']=false;
                st.pop_back();
            }

            st.push_back(it);
            vis[it-'a']=true;
        }

        return st;
    }
};
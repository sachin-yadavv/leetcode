class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maximum=0;
        for(string sentence:sentences){
            int count=1;
            for(int i=0;i<sentence.size();i++){
                if(sentence[i]==' '){
                    count++;
                }
            }
            maximum=max(maximum,count);
        }
        return maximum;
    }
};
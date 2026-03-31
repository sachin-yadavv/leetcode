class Solution {
public:
   bool isSame(string &ans, string &str2 , int i , int m ){
    for(int j=0;j<m;j++){
        if(ans[i]!=str2[j]) return false;

        i++;
    }
    return true;
   }

    string generateString(string str1, string str2) {
        int n = str1.size();
        int m=str2.size();

        int N=n+m-1;
        string ans(N,'#');
        vector<bool>flag(N,false);

  // for processing the T
        for(int i=0;i<n;i++){
            if(str1[i] == 'T') {
            int a=i;
            for(int j=0;j<m;j++){
                if(ans[a]!='#' && ans[a]!=str2[j]) return "";
                ans[a]=str2[j];
                a++;
            }
            }
        }
  // fill remaning with a 

        for(int i=0;i<N;i++){
            if(ans[i]=='#'){
               ans[i]='a';
               flag[i]=true;
              }
       }


  // process the  F
      for(int i = 0; i < n; i++) {
          if(str1[i] == 'F') {

             if(isSame(ans, str2, i, m)) { //If same, then we need to make it unequal

            bool changed = false;
            for(int k = i + m - 1; k >= i; k -- ) {
               if(flag[k] == true) {
                 ans [k] = 'b';
                 changed = true;
                 break;
               }
            }
            
            if(changed == false)  // if we are not able to change any char then return ""
            return "";
             }

          }
      }


        return ans;
    }
};
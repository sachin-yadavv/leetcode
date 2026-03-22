class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
         int n=nums1.size();
        int mini=INT_MAX;
        int e=0;
        int o=0;

        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                e++;
                mini=min(mini,nums1[i]);
            }
            else{
                 o++;
                mini=min(mini,nums1[i]);
            }
        }

        if(e==n || o==n)
            return true;
        

        else if(mini%2==0){
            sort(nums1.begin(),nums1.end());
    
            for(int i=1;i<n;i++){

                if(nums1[i]%2==0)
                    continue;
                
                else{
                    if(((nums1[i]-mini)%2)!=0){
                        return false;
                    }
                }
            }
            return true;
        }
        else{
                
            sort(nums1.begin(),nums1.end());

            for(int i=1;i<n;i++){
                if(nums1[i]%2!=0)
                    continue;
                
                else{
                    if(((nums1[i]-mini)%2)==0){
                        return false;
                    }
                }
            }

            return true;
        }
    }
};
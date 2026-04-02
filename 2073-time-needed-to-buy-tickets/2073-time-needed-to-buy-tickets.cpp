class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int cnt=0;
        int n = tickets.size();
        int i=0;
        while(tickets[k]!=0){
            if(tickets[i%n]!=0){
                cnt++;
                tickets[i%n]--; 
                i++;   
            }
            else i++;
        }
        return cnt;
    }
};
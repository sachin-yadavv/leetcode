/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* get(ListNode* temp,int k ){
    k--;
    while(temp!=NULL && k>0){
        k--;
        temp=temp->next;
    }
    return temp;

}
ListNode* reverse(ListNode* head){
    ListNode* temp=head;
    ListNode* prev=NULL;
    while(temp!=NULL){
        ListNode* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;

    }
    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
         if (!head || k == 1) return head;
        ListNode* temp=head;
        ListNode* nextNode;
        ListNode* prevNode;
        while(temp!=NULL){
           ListNode* kthNode=get(temp,k);

            if(kthNode==NULL){
              if(prevNode!=NULL)  prevNode->next=temp;
                break;
            }
            nextNode=kthNode->next;
            kthNode->next=NULL;
            reverse(temp);

            if(temp==head){
                head=kthNode;
            }
            else{
                prevNode->next=kthNode;
            }
                prevNode=temp;
                temp=nextNode;
        }


        
        return head;
    }
};
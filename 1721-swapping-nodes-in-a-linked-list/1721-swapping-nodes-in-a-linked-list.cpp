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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        
        for(int i = 1; i < k; i++){
            temp = temp->next;
        }

        ListNode* kthStart = temp;
        ListNode* second = head;

        while(temp->next){
            temp = temp->next;
            second = second->next;
        }

        swap(kthStart->val, second->val);

        return head;
    }
};
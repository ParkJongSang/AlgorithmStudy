/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = l1->val + l2->val;
        int carry = sum/10;
        ListNode *head = new ListNode(sum%10);
        ListNode *p = head;
        l1 = l1->next;
        l2 = l2->next;
        
        while(l1 != NULL || l2 != NULL) {
            int x = l1 != NULL ? l1->val : 0;
            int y = l2 != NULL ? l2->val : 0;
            sum = x + y + carry;
            carry = sum/10;
            
            p->next = new ListNode(sum%10);
            p = p->next;
            
            if(l1 != NULL) l1 = l1>next;
            if(l2 != NULL) l2 = l2->next;
        }
        if( carry > 0 ) {
            p -> next = new ListNode(carry);
        }
        return head;
        
    }
};-

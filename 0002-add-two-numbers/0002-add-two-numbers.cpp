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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return NULL;\

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int sum = 0;
        int carry = 0;

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(temp1 != NULL || temp2 != NULL){
            
            int val1 = 0;
            int val2 = 0;
            
            if(temp1 != NULL) val1 = temp1 -> val;
            if(temp2 != NULL) val2 = temp2 -> val;

            sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            ListNode* ans = new ListNode(sum);

            tail -> next = ans;
            tail = tail -> next;

            if(temp1 != NULL) temp1 = temp1 -> next;
            if(temp2 != NULL) temp2 = temp2 -> next;
        }

        if(carry){
            tail->next = new ListNode(carry);
        }

        return dummy -> next;
    }
};
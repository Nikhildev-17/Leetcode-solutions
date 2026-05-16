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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count ++;
            temp = temp -> next;
        }
        if(count == n){
            return head -> next;
        }

        int n1 = count - n;
        count = 0;
        temp = head;
        while(count < n1 - 1){
            temp = temp -> next;
            count ++;
        }
        temp -> next = temp -> next -> next;

        return head;
    }
};
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        int length = 0;
        ListNode* curr = head;

        while(curr != NULL){
            length++;
            curr = curr->next;
        }
        k = k % length;
        ListNode* temp;
        ListNode* tail;
        ListNode* prev;

        int count = 0;
        while(count < k){
            temp = head;
            while(temp -> next != NULL){
                prev = temp;
                temp = temp -> next;
            }
            tail = temp;
            tail -> next = head;
            prev -> next = NULL;
            head = tail;

            count++;
        }
        return head;
    }
};
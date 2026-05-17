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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if(headA == NULL || headB == NULL) return NULL;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        int lenA = 0;
        while(temp1 != NULL){
            lenA++;
            temp1 = temp1 -> next;
        }

        int lenB = 0;
        while(temp2 != NULL){
            lenB++;
            temp2 = temp2 -> next;
        }

        int diff = (lenA >= lenB)? (lenA - lenB) : (lenB - lenA);

        temp1 = headA;
        temp2 = headB;
        int count = 0;

        if(lenA >= lenB){
            while(count < diff){
                temp1 = temp1 -> next;
                count++;
            }
        }else{
            while(count < diff){
                temp2 = temp2 -> next;
                count++;
            }
        }

        while(temp1 != NULL && temp2 != NULL){
            if(temp1 == temp2)
                return temp1;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        return NULL;
    }
};
/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: a ListNode
     * @param v1: An integer
     * @param v2: An integer
     * @return: a new head of singly-linked list
     */
    ListNode * swapNodes(ListNode * head, int v1, int v2) {
        // write your code here
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;

        //get the prev1, prev2
        ListNode* prev1 = NULL;
        ListNode* prev2 = NULL;

        while(temp->next){
            if(temp->next->val == v1){
                prev1 = temp;
            } else if(temp->next->val == v2){
                prev2 = temp;
            }

            //both found, break
            if(prev1 && prev2){
                break;
            }

            temp = temp->next;
        }

        if(!prev1 || !prev2) return head;

        ListNode* n1 = prev1->next;
        ListNode* n2 = prev2->next;
        //ListNode* next2 = n2->next;

        prev1->next = n2;
        prev2->next = n1;
        //store n2->next
        ListNode* next2 = n2->next;
        n2->next = n1->next;
        n1->next = next2;

        return dummy->next;
    }


};

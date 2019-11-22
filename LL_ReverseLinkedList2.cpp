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
     * @param head: ListNode head is the head of the linked list
     * @param m: An integer
     * @param n: An integer
     * @return: The head of the reversed ListNode
     */
    ListNode * reverseBetween(ListNode * head, int m, int n) {
        // write your code here
        //get a dunmmy
        ListNode* dunmmy = new ListNode();
        dunmmy->next = head;
        ListNode* p = dunmmy;//modified here
        //get the (m-1)th as p
        for(int i = 0; i < m-1; i++){
            p = p->next;
        }
        //get the mth as tail
        ListNode* tail = p->next;

        //reverse the m to n
        ListNode* prev = p;
        ListNode* curr = p->next;
        for(int i = m; i < n+1; i++){
            //store the next
            ListNode* next = curr->next;
            //reverse
            curr->next = prev;
            //forward
            prev = curr;//modified here
            curr = next;
        }

        //connect
        p->next = prev;
        tail->next = curr;

        //return the revered List
        return dunmmy->next;
    }
};

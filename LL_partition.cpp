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
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
    ListNode * partition(ListNode * head, int x) {
        // write your code here
        ListNode* leftDummy = new ListNode();
        ListNode* rightDummy = new ListNode();
        ListNode* leftTail = leftDummy;
        ListNode* rightTail = rightDummy;

        //loop
        while(head){
            if(head->val < x){
                //leftDummy->next = head;
                leftTail->next = head;//modified here, do not move dummy
                leftTail = head;
            } else {
                //rightDummy -> next = head;
                rightTail -> next = head;
                rightTail = head;
            }
            head = head -> next;
        }
        //connect
        leftTail -> next = rightDummy -> next;
        rightTail -> next = NULL;

        return leftDummy->next;
    }
};

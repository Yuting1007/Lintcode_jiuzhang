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
     * @param head: the List
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode * rotateRight(ListNode * head, int k) {
        // write your code here
        //need to change head, don not use dummy
        if(head == NULL){
            return head;
        }

        int len = getLength(head);
        k = k % len;

        if(k == 0){
            return head;
        }
        //fast move k steps
        ListNode* fast = head;
        for(int i = 0; i < k; i++){
            fast = fast->next;
        }
        ListNode* slow = head;
        //fast and slow move together until fast reach the end
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        //connect
        fast->next = head;
        head = slow->next;
        slow->next = NULL;

        return head;
    }

private:
    int getLength(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }
};

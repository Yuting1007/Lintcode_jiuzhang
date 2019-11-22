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
     * @param head: The head of linked list.
     * @return: nothing
     */
    void reorderList(ListNode * head) {
        // write your code here
        if(head == NULL || head->next == NULL){
            return;
        }

        // ListNode* dummy = new ListNode(0);
        // dummy->next = head;

        //find the mid
        ListNode* mid = findMid(head);
        //get the heads for two sublists
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = NULL;
        //get the head of reversed part2 sublist
        l2 = reverse(l2);
        //reconstruct the list
        while(l1 != NULL && l2 != NULL){
            ListNode* next1 = l1->next;
            ListNode* next2 = l2->next;
            l1->next = l2;
            l2->next = next1;
            l1 = next1;
            l2 = next2;
        }
        //return dummy->next;

    }

private:
    ListNode* findMid(ListNode* head){
        if(head == NULL) return head;
        //fast slow pointer
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

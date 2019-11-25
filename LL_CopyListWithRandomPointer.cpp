/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if(head == NULL){
            return head;
        }

        RandomListNode* curr = head;
        //first pass, insert copy nodes
        while(curr){
            RandomListNode* copy = new RandomListNode(curr->label);
            copy->next = curr->next;
            curr->next = copy;
            curr = curr->next->next;
        }
        //second, connect random pointer
        curr = head;
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        //third, pick up copy nodes
        curr = head;
        RandomListNode* dummy = new RandomListNode(0);
        RandomListNode* copyPrev = dummy;
        while(curr){
            copyPrev->next = curr->next;
            curr->next = curr->next->next;
            copyPrev = copyPrev->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};

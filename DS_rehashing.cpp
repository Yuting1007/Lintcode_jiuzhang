/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        //create a new hashTable with the double size
        int capacity = 2 * hashTable.size();
        vector<ListNode*> result(capacity);

        for(int i = 0; i < hashTable.size(); i++){
            ListNode* head = hashTable[i];
            while(head != NULL){
                int newIdx = (capacity + head->val % capacity) % capacity;
                //if the new position is empty, insert the element
                if(result[newIdx] == NULL){
                    result[newIdx] = new ListNode(head->val);
                } else {
                    //if it is not empty, insert the element to the next empty position
                    ListNode* curr = result[newIdx];
                    while(curr->next != NULL){
                        curr = curr->next;
                    }
                    curr->next = new ListNode(head->val);
                }
                head = head->next;
            }

        }
        return result;

    }
};

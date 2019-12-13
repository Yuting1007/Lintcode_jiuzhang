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

 struct compare{
     bool operator()(const ListNode* l, const ListNode* r){
         return l->val > r->val;
     }
 };

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if(lists.size() == 0){
            return NULL;
        }
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        //iterate the list
        //push the head of all lists to the pq
        for(auto i : lists){
            if(i){
                pq.push(i);
            }
        }

        //start a result linked list
        //这里记住, 真的常用
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        //push the smallest head(in pq) to the result
        //then add the next node of the chosen node to pq
        //until the pq is empty
        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            curr->next = temp;//add to the result;
            curr = curr->next;//move the pointer
            temp = temp->next;
            if(temp){
                pq.push(temp);
            }
        }
        return dummy->next;
    }
};

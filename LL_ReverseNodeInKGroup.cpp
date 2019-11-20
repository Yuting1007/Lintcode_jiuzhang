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
     * @param k: An integer
     * @return: a ListNode
     */
    ListNode * reverseKGroup(ListNode * head, int k) {
        // write your code here
        int len = getLenth(head);
        //base case, k = 0 or len less than k
        if(k <= 0 || k > len){
            return head;//cannot inverse
        }
        //find the kth node
        ListNode* h1 = findkth(head, k);
        ListNode* h2 = h1->next;
        //cut off
        h1 -> next = NULL;//modified here, cut off

        //reverse the sublist (head head, end h1)
        ListNode* ans = reverse(head);
        //coonect with the rest reversed lsit
        //now the head is at the end of sublist
        head->next = reverseKGroup(h2, k);

        //return ans
        return ans;
    }

private:
    int getLenth(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count ++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* findkth(ListNode* head, int k){
        ListNode* temp = head;//modified here, not change the head
        for(int i = 0; i < k - 1; i++){
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverse(ListNode* head){
        //base case
        if(!head || !head->next){
            return head;
        }//modified here, add base case

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr){
            //store
            next = curr -> next;
            //reverse
            curr -> next = prev;
            //one step forward
            prev = curr;
            curr = next;
        }

        //return
        return prev;//modified here
    }
};

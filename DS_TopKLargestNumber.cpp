class Solution {
public:
    /*
    * @param k: An integer
    */Solution(int k) {
        // do intialization if necessary
        maxSize = k;
    }

    /*
     * @param num: Number to be added
     * @return: nothing
     */
    void add(int num) {
        // write your code here
        if(pq.size() < maxSize){
            pq.push(num);
        } else if(num > pq.top()){
            pq.pop();
            pq.push(num);
        }
    }

    /*
     * @return: Top k element
     */
    vector<int> topk() {
        // write your code here
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        //reset the pq
        for(int val : result){
            pq.push(val);
        }
        //for now the smaller element at the front in the result
        //reverse it
        reverse(result.begin(), result.end());
        return result;
    }

private:
    int maxSize;
    priority_queue <int, vector<int>, greater<int>> pq;//a syntax of a minheap
    //top() the largest priority
    //pop() the first element
    //push() add element at the end of the queue
};

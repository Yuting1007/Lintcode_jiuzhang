//Binary tree level order traversal
//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> result;
        //base case
        if(root == NULL){
            return result;
        }
        //create a queue
        queue <TreeNode*> q;
        //push the root into the queue
        q.push(root);
        //while the q is not empty, expand the queue
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            //expand the q by level
            for(int i = 0; i < size; i++){
                TreeNode* head = q.front();
                q.pop();
                level.push_back(head->val);
                if(head->left != NULL){
                    q.push(head->left);
                }
                if(head->right != NULL){
                    q.push(head->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};

//For each directed edge A -> B in graph, A must before B in the order list.
//The first node in the order can be any node in the graph with no nodes direct to it.
class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        queue<DirectedGraphNode*> q;
        unordered_map<DirectedGraphNode*, int> m;
        vector<DirectedGraphNode*> answer;

        // First round
        //gain degree information
        for(auto node : graph){
            for(auto neighbor : node->neighbors){
                m[neighbor] += 1;
            }
        }

        // Check for zero
        //if the degree is zero(no pre), enqueue
        for(auto node : graph){
            if(m[node] == 0){
                q.push(node);
                answer.push_back(node);
            }
        }

        // Second round
        //start topological sorting
        while(!q.empty()){
            DirectedGraphNode *curr = q.front();
            q.pop();
            for(auto neighbor : curr->neighbors){
                m[neighbor] -= 1;
                if(m[neighbor] == 0){
                    q.push(neighbor);
                    answer.push_back(neighbor);
                }
            }
        }

        return answer;
    }

};

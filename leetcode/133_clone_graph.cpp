/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return nullptr;
            
        unordered_map<int, UndirectedGraphNode *> node_set;
        unordered_set<int> seen;
        queue<UndirectedGraphNode *> q;
        
        q.push(node);
        
        UndirectedGraphNode *clone = new UndirectedGraphNode(node->label);
        node_set[clone->label] = clone;
        
        while(!q.empty()) {
            UndirectedGraphNode *curr = q.front();
            q.pop();
            
            int label = curr->label;
            
            if(seen.find(label) != seen.end())
                continue;
            
            seen.insert(label);
            
            for(auto neighbor: curr->neighbors) {
                if(node_set.find(neighbor->label) == node_set.end())
                    clone = new UndirectedGraphNode(neighbor->label);
                else
                    clone = node_set[neighbor->label];
                    
                node_set[clone->label] = clone;
                node_set[label]->neighbors.push_back(clone);
                
                q.push(neighbor);
            }
        }
        
        return node_set[node->label];
    }
};

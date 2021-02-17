#pragma once

// 133. Return a deep copy (clone) of the graph.

// Solution: (complexity O(N))
// We basically keep a map of original -> cloned nodes.
// We perform a BFS on the graph, pushing new neighbors
// into the bfs queue while cloning them. We also push
// the cloned neighbor to the neighbor array of the current node.
// Then all we have to do is return the cloned version of root.

SOLUTION_FOR_PROBLEM(133, "Clone Graph") {

// Definition for a Node. (from leetcode)
class Node {
public:
    int val;
    std::vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }

    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraph(Node* node)
{
    if (!node)
        return nullptr;

    std::queue<Node*> nodes;
    std::unordered_map<Node*, Node*> org_to_clone;

    org_to_clone[node] = new Node(node->val);
    nodes.push(node);

    while (!nodes.empty()) {
        auto* node = nodes.front();
        nodes.pop();

        for (auto neighbour : node->neighbors) {
            if (!org_to_clone.count(neighbour)) {
                org_to_clone[neighbour] = new Node(neighbour->val);
                nodes.push(neighbour);
            }

            org_to_clone[node]->neighbors.push_back(org_to_clone[neighbour]);
        }

    }

    return org_to_clone[node];
}

SOLVE()
{
    // some tests...
}

}

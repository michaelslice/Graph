#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

void bfs(Node* startNode, unordered_map<Node*, bool>& visited) {
    if (!startNode) return;

    // Create a queue for BFS
    queue<Node*> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        // Get the current node
        Node* node = q.front();
        q.pop();

        // Process the node
        cout << node->val << " ";

        // Visit all unvisited neighbors
        for (Node* neighbor : node->neighbors) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Create graph nodes
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    // Define neighbors
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    // Create visited map
    unordered_map<Node*, bool> visited;

    // Perform BFS starting from node1
    cout << "BFS Traversal: ";
    bfs(node1, visited);

    // Clean up dynamically allocated memory
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}

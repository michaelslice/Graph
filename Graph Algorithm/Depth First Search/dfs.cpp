#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <map>
#include <queue>
#include <stack>
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

void dfs(Node* node, unordered_map<Node*, bool>& visited){
    if(!node) return;

    cout << node->val << endl;
    visited[node] = true;

    for(Node* neighbor : node->neighbors){
        if(!visited[neighbor]){
            dfs(neighbor, visited);
        }
    }
};

int main(){
    
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node1, node2};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node4, node1};
    node4->neighbors = {node2, node4};

    unordered_map<Node*, bool> visited;

    dfs(node1, visited);

    return 0;
}
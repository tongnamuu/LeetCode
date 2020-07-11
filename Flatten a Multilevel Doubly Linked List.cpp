/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
   public:
    queue<Node*> q;
    void solve(Node* node) {
        if (!node) return;
        q.push(node);
        solve(node->child);
        solve(node->next);
    }
    Node* flatten(Node* head) {
        Node* temp = head;
        solve(temp);
        Node* prev = nullptr;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            p->child = nullptr;
            if (prev) prev->next = p, p->prev = prev;
            prev = p;
        }
        return head;
    }
};
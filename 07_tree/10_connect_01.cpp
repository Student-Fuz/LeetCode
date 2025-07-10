#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int qSize = q.size();

            for(int i = 0; i < qSize-1; i++){
                Node* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                node->next = q.front();
            }
            Node* node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

        }

        return root;
    }
};

int main() {

    return 0;
}

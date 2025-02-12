#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/


// Definition for a Node.
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


// Solution
// m1: 递归遍历法
class Solution {
public:
    void visit(Node* cur){

    }
    Node* connect(Node* root) {
        
    }
};

// m2:循环遍历
class Solution {
public:  
    Node* connect(Node* root) {
        queue<Node*> que;
        if(root == NULL) return root;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            Node* cur;
            for(int i = 0; i < size; i++){
                // 下一层节点
                if(que.front()->left != nullptr) que.push(que.front()->left);
                if(que.front()->right != nullptr) que.push(que.front()->right);
                // 连接操作
                cur = que.front();
                que.pop();
                cur->next = que.front();
            }
            cur->next = NULL;
        }
        return root;
    }
};


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}
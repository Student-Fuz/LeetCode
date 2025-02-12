#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/binary-tree-level-order-traversal/description/

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// 递归法 标准答案 
class Solution {
public:

    // 后序访问
    void order(Node* cur, vector<vector<int>>& result, int depth)
    {
        if (cur == nullptr) return;
        if (result.size() == depth) result.push_back(vector<int>());
        for(int i = 0; i < cur->children.size(); i++){
            order(cur->children[i], result, depth+1);
        }
        result[depth].push_back(cur->val);
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        int depth = 0;
        order(root, result, depth);
        return result;
    }
};


int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}
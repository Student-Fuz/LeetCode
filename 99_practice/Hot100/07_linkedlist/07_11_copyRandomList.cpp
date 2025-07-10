#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/intersection-of-two-linked-lists/description/?envType=study-plan-v2&envId=top-100-liked

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;

        unordered_map<Node*, Node*> old_new_map;

        Node* cur = head;
        Node* newHead = new Node(head->val);
        Node* newPre = newHead;
        newHead->random = head->random;
        old_new_map[head] = newHead;
        Node* newCur;
        cur = cur->next;
        while(cur != NULL){
            newCur = new Node(cur->val);
            newCur->random = cur->random;
            old_new_map[cur] = newCur;
            newPre->next = newCur;
            newPre = newCur;
            cur = cur->next;
        }

        newCur = newHead;
        while(newCur != NULL){
            newCur->random = old_new_map[newCur->random]; 
            newCur = newCur->next;
        }

        return newHead;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}
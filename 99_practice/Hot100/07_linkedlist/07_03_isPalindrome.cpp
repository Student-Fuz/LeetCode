#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/palindrome-linked-list/?envType=study-plan-v2&envId=top-100-liked

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution
// m1: 转换成数组，双指针进行判断 （略）
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
    }
};

// m2: 递归
class Solution {
private:
    bool check(ListNode* cur, ListNode*& front){
        if(cur != NULL){
            if(!check(cur->next, front))
                return false;
            if(cur->val != front->val)
                return false;
            front = front->next;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* front = head;
        return check(head, front);
    }
};
  

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}
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

struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};


// Solution
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> showed;

        ListNode *cur = head;
        while(cur != NULL){
            if(showed.find(cur) == showed.end()){
                showed.insert(cur);
            }
            else{
                return cur;
            }
            cur = cur->next;
        }
        return cur;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}
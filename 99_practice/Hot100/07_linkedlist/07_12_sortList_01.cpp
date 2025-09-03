#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 转换成数组进行处理
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> vec;

        ListNode* cur = head;
        while(cur != NULL){
            vec.push_back(cur->val);
            cur = cur->next;
        }

        sort(vec.begin(), vec.end());

        cur = head;
        int i = 0;
        while(cur != NULL){
            cur->val = vec[i++];
            cur = cur->next;
        }

        return head;
    }
};

int main() {

    return 0;
}
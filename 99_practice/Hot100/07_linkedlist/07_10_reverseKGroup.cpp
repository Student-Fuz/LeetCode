#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/reverse-nodes-in-k-group/description/?envType=study-plan-v2&envId=top-100-liked

struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

// TODO
// try1
// Solution
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> nodes(k, nullptr);

        ListNode* tmp = head;
        ListNode* result;
        for(int i = 0; i < k; i++){
            nodes[i] = tmp;
            tmp = tmp->next;
        }
        result = nodes.back();
        while(true){
            ListNode* next = nodes.back()->next;
            for(int i = k-1; i > 0; i--){
                nodes[i]->next = nodes[i-1];
            }

            // 判断剩余节点是否足够k个
            if(next == nullptr){
                nodes[0]->next = nullptr;
                break;
            }
            else{
                int j = 2;
                nodes[1] = next->next;
                while(nodes[j-1] != NULL && j < k){
                    nodes[j] = nodes[j-1]->next;
                    j++; 
                }
                // 剩余节点不足k个
                if(nodes[j-1] == NULL){
                    nodes[0]->next = next;
                    break;
                }
                // 剩余节点足够k个
                else{
                    nodes[0] = next;
                }
            }
        }
        return result;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}
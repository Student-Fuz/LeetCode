#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <functional>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/top-k-frequent-elements/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
public:
    class myCmp{
    public:
        bool operator()(pair<int, int> l, pair<int, int> r){
            return l.second > r.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // key--num; value--freq
        unordered_map<int, int> freqMap;

        for(const int& num : nums)
            freqMap[num]++;

        // 默认最大堆
        // std::priority_queue<int> pq;

        // 创建一个最小堆
        // std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        // 使用小顶堆
        priority_queue<pair<int,int>, vector<pair<int, int>>, myCmp> minHeap;

        for(const auto& pair : freqMap){
            minHeap.push(pair);
            if(minHeap.size() > k)
                minHeap.pop();
        }

        // vector<int> result;
        // for(int i = 0; i < k; i++){
        //     result.push_back(minHeap.top().first);
        //     minHeap.pop();
        // }

        // 按照从大到小的顺序弹出
        vector<int> result(k, 0);
        for(int i = k-1; i >= 0; i--){
            result[i] = (minHeap.top().first);
            minHeap.pop();
        }

        return result;
    }
};

// 自写堆排序 TODO

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// 链接：https://github.com/youngyangyang04/leetcode-master

class GreaterSecond{
public:
    bool operator()(pair<int, int> l, pair<int, int> r){
        return l.second > r.second;
    }
};

// 优先队列
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for(const auto& num : nums){
            freqMap[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, GreaterSecond> min_pq; 

        for(const auto& pair : freqMap){
            min_pq.push(pair);
            if(min_pq.size() > k)
                min_pq.pop();
        }

        vector<int> result;
        while(!min_pq.empty()){
            result.push_back(min_pq.top().first);
            min_pq.pop();
        }

        return result;
    }
};

int main() {

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class GreaterSecond{
public:
    bool operator()(pair<int, int> l, pair<int, int> r){
        return l.second > r.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // key--num val--freq
        unordered_map<int, int> freqMap;

        for(const auto& num : nums){
            freqMap[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, GreaterSecond> minHeap;


        for(const auto fpair : freqMap){
            minHeap.push(fpair);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        vector<int> result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return result;
    }
};

int main() {


    return 0;
}
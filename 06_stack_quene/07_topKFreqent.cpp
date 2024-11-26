#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>

using namespace std;

// 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

 

// 示例 1:

// 输入: nums = [1,1,1,2,2,3], k = 2
// 输出: [1,2]
// 示例 2:

// 输入: nums = [1], k = 1
// 输出: [1]
 

// 提示：

// 1 <= nums.length <= 105
// k 的取值范围是 [1, 数组中不相同的元素的个数]
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 

// 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。

// 暴力方法
// 时间复杂度O(n+nlogn+n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequent_table;
        multimap<int, int> frequent_map;
        vector<int> result;
        for(auto num : nums){
            // auto it = frequent_table.find(num);
            // if(it != frequent_table.end())
            //     it->second++;
            // else
            //     frequent_table[num] = 1;
            frequent_table[num]++;
        }
        // 排序出前k----性能障碍
        for(auto it : frequent_table){
            frequent_map.insert({it.second,it.first});
        }

        for (auto it = frequent_map.rbegin(); it != frequent_map.rend() && k > 0; ++it, --k)
            result.push_back(it->second);

        return result;
    }
};

// 最小顶堆方法
// 大顶堆----堆头是最大元素 小顶对----堆头是最小元素
// 时间复杂度O(n+nlogn+n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequent_table;
        vector<int> result;
        for(auto num : nums)
            frequent_table[num]++;

        // 大的排在队列前 这里的堆的底层实现是完全二叉树
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> min_heap;
        for(auto& [num, freq] : frequent_table){
            min_heap.emplace(freq, num);
            if(min_heap.size() > k)
                min_heap.pop();
        }

        while(!min_heap.empty()){
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
            

        return result;
    }
};

int main(){

    Solution s;

    return 0;
}
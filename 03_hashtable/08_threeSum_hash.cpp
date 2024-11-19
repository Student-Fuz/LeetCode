#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>

using namespace std;

// 超时 TODO 自定义哈希函数
// 自定义 hash 函数，用于 multiset<int>
struct hash_multiset {
    template <typename T>
    size_t operator()(const std::multiset<T>& mset) const {
        size_t hash_value = 0;
        for (const auto& elem : mset) {
            hash_value ^= std::hash<T>{}(elem) + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
        }
        return hash_value;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 用 multiset 简化嵌套的数据结构
        unordered_map<int, unordered_set<multiset<int>, hash_multiset>> sum_n1_n2;
        unordered_set<multiset<int>, hash_multiset> result_set;

        for (int i = 1; i < nums.size(); i++) {
            // 检查是否存在满足条件的前两个数
            int target = 0 - nums[i];
            auto it1 = sum_n1_n2.find(target);
            if (it1 != sum_n1_n2.end()) {
                for (const auto& pair : it1->second) {
                    multiset<int> result = pair; // 拷贝已有的 multiset
                    result.insert(nums[i]);      // 加入第三个数
                    result_set.insert(result);  // 插入结果集合
                }
            }

            for (int j = 0; j < i; ++j) {
               // 插入或更新两数之和的 map
                int sum = nums[i] + nums[j];
                if (sum_n1_n2.find(sum) != sum_n1_n2.end()) {
                    sum_n1_n2[sum].insert({nums[i], nums[j]});
                } else {
                    sum_n1_n2[sum] = {{nums[i], nums[j]}};
                }
            }
        }

        // 转换为 vector<vector<int>>
        vector<vector<int>> result_vector;
        for (const auto& triplet : result_set) {
            result_vector.emplace_back(triplet.begin(), triplet.end());
        }

        return result_vector;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 0, 0, 0};

    vector<vector<int>> result = sol.threeSum(nums);

    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

 

// 示例 1：

// 输入：haystack = "sadbutsad", needle = "sad"
// 输出：0
// 解释："sad" 在下标 0 和 6 处匹配。
// 第一个匹配项的下标是 0 ，所以返回 0 。
// 示例 2：

// 输入：haystack = "leetcode", needle = "leeto"
// 输出：-1
// 解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
 

// 提示：

// 1 <= haystack.length, needle.length <= 104
// haystack 和 needle 仅由小写英文字符组成


// 有趣的解法-0-1-2
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<bool> track_map;
        // val-0-not reached val-1-reached val-2-started from there 
        track_map.assign(nums.size(), false);

        vector<int> cur_poses = {0};
        vector<int> next_poses = {};

        cur_poses.reserve(nums.size());
        next_poses.reserve(nums.size());

        int step_count = 0;

        while(1){
            for(int cur_pos : cur_poses){
                if(cur_pos == nums.size()-1)
                    return step_count;
                // 从当前位置出发
                for(int step_len = nums[cur_pos]; step_len > 0; step_len--){
                    int next_pos = cur_pos+step_len;
                    // 如果抵达终点
                    if(next_pos >= nums.size()-1)
                        return ++step_count;
                    if(track_map[next_pos] == false){
                        next_poses.push_back(next_pos);
                        track_map[next_pos] == true;
                    }
                }
            }
            if(next_poses.empty())
                break;
            // cur_poses = next_poses;
            // next_poses.clear();

            cur_poses.swap(next_poses);
            next_poses.clear();

            step_count++;
        }
            return step_count;
    }
};

// 有趣的解法--unordered_map
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> track_map;
        // val-0-not reached val-1-reached val-2-started from there 
        track_map.assign(nums.size(), 0);

        unordered_set<int> cur_poses = {0};
        unordered_set<int> next_poses = {};

        int step_count = 0;

        while(1){
            for(int cur_pos : cur_poses){
                if(cur_pos == nums.size()-1)
                    return step_count;
                // 从当前位置出发
                for(int step_len = nums[cur_pos]; step_len > 0; step_len--){
                    int next_pos = cur_pos+step_len;
                    // 如果抵达终点
                    if(next_pos >= nums.size()-1)
                        return ++step_count;
                    if(track_map[next_pos] != 2){
                        next_poses.insert(next_pos);
                    }
                }
                // 从当前位置出发后标记
                track_map[cur_pos] = 2;
            }
            if(next_poses.empty())
                break;
            cur_poses = next_poses;
            next_poses.clear();
            step_count++;
        }
            return step_count;
    }
};

int main(){

    Solution s;

    return 0;
}
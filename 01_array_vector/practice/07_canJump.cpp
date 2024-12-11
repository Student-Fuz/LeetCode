#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

// 判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。

// 有趣的解法--0-1-2
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> track_map;
        // val-0-not reached val-1-reached 
        track_map.assign(nums.size(), 0);

        vector<int> cur_poses = {0};
        vector<int> next_poses = {};

        while(1){
            for(int cur_pos : cur_poses){
                // 从当前位置出发
                for(int step_len = nums[cur_pos]; step_len >= 0; step_len--){
                    int next_pos = cur_pos+step_len;
                    // 如果抵达终点
                    if(next_pos >= nums.size()-1)
                        return true;
                    if(track_map[next_pos] == 0){
                        next_poses.push_back(next_pos);
                        track_map[next_pos] = 1;
                    }
                }
                // 从当前位置出发后标记
                track_map[cur_pos] = 2;
            }
            if(next_poses.empty())
                break;
            cur_poses = next_poses;
            next_poses.clear();
        }
            return false;
    }
};

// 有趣的解法--unordered_map
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> track_map;
        // val-0-not reached val-1-reached val-2-started from there 
        track_map.assign(nums.size(), 0);

        unordered_set<int> cur_poses = {0};
        unordered_set<int> next_poses = {};

        while(1){
            for(int cur_pos : cur_poses){
                // 从当前位置出发
                for(int step_len = nums[cur_pos]; step_len >= 0; step_len--){
                    int next_pos = cur_pos+step_len;
                    // 如果抵达终点
                    if(next_pos >= nums.size()-1)
                        return true;
                    if(track_map[next_pos] != 2){
                        next_poses.insert(next_pos);
                        // track_map[next_pos] = 1;
                    }
                }
                // 从当前位置出发后标记
                track_map[cur_pos] = 2;
            }
            if(next_poses.empty())
                break;
            cur_poses = next_poses;
            next_poses.clear();
        }
            return false;
    }
};

int main(){

    Solution s;

    return 0;
}
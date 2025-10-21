#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        if(nums.size() <= 1) return 0;
        // 左闭右开
        int start = 0, end = 1; 
        // val times
        unordered_map<int, int> map;
        map[nums[start]]++;
        long long cnt = 0;
        int mk = 0;
        for(int start = 0; start < nums.size(); start++){
            while(mk < k && end < nums.size()){
                map[nums[end]]++;
                mk += map[nums[end]]-1;
                end++;
            }
            if(mk >= k) cnt += (nums.size() - end + 1);
            map[nums[start]]--;
            mk -= map[nums[start]];
        }
        return cnt;
    }
};

int main() {

    return 0;
}
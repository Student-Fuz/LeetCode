#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

// 题目描述


// Solution
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort排序默认升序

        // 降序排列
        // sort(g.begin(), g.end(), [](int a, int b) { return a > b; });
        // sort(s.begin(), s.end(), [](int a, int b) { return a > b; });

        // 升序排列
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int res = 0;

        while((!s.empty()) && (!g.empty())){
            int cur_size = s.back();
            // 已有饼干无法满足孩子
            if(cur_size < g[0])
                break;
            // 将此饼干给刚好满足的孩子
            auto child = lower_bound(g.begin(), g.end(), cur_size);
            if(child != g.end()){
                g.erase(child);
                res++;
            }
            s.pop_back();
        }
        
        return res;
    }
};

int main(){

    Solution s;

    return 0;
}
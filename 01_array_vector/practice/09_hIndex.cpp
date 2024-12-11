#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;

// 题目描述
// 给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数。计算并返回该研究者的 h 指数。

// 根据维基百科上 h 指数的定义：h 代表“高引用次数” ，一名科研人员的 h 指数 是指他（她）至少发表了 h 篇论文，并且 至少 有 h 篇论文被引用次数大于等于 h 。如果 h 有多种可能的值，h 指数 是其中最大的那个


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0;
        int h_candidate;
        int citation_num = 0;
        int papers_upper_sum = 0;
        map<int, int> freq_map;
        for(auto citation : citations){
            freq_map[citation]++;
        }

        for(auto it = freq_map.rbegin(); it != freq_map.rend(); it++){
            citation_num = it->first;
            // papers_upper_sum：引用超过it->first的文章数量
            papers_upper_sum += it->second;
            h_candidate = min(papers_upper_sum, citation_num);
            if(papers_upper_sum >= citation_num){
                break;
            }
            h = max(h, h_candidate);
        }
        return h;

    }
};

int main(){

    Solution s;

    return 0;
}
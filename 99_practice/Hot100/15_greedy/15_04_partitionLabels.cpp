#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/sort-colors/solutions/437968/yan-se-fen-lei-by-leetcode-solution/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);

        for(int i = 0; i < s.size(); i++){
            last[s[i] - 'a'] = i; 
        }

        int start = 0;
        int end = 0;
        vector<int> result;
        for(int i = 0; i < s.size(); i++){
            end = max(end, last[s[i] - 'a']);
            if(i == end){
                result.push_back(end-start+1);
                start = end + 1;
            }
        }

        return result;
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}
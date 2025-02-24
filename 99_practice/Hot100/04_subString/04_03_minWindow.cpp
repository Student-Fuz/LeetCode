#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/minimum-window-substring/?envType=study-plan-v2&envId=top-100-liked

// Solution
class Solution {
private:
    bool isCovered(const vector<int>& charMap_s, const vector<int>& charMap_t){
        bool flag = true;
        for(int i = 0; i < 52; i++){
            if(charMap_t[i] > charMap_s[i]){
                flag = false;
                break;
            }
        }
        return flag;
    }
public:
    string minWindow(string s, string t) {
        vector<int> charMap_s(52, 0);
        vector<int> charMap_t(52, 0);

        for(int i = 0; i < t.size(); i++){
            if(t[i] >= 'a' && t[i] <= 'z')
                charMap_t[t[i] - 'a']++;
            else    
                charMap_t[t[i] - 'A' + 26]++;
        }
     
        // 区间左闭右闭
        int front = 0, back = 0;
        int min_front = 0;
        int minWindowLength = s.size() + 1;
        bool coveredFlag = false;

        while(back < s.size()){
            // 先扩张右侧，再收缩左侧
            coveredFlag = false;
            // 1. 扩张右侧
            while(back < s.size()){
                if(s[back] >= 'a' && s[back] <= 'z')
                    charMap_s[s[back] - 'a']++;
                else    
                    charMap_s[s[back] - 'A' + 26]++;

                coveredFlag = isCovered(charMap_s, charMap_t);
                if(coveredFlag) break;
                back++;
            }

            // 2. 收缩左侧
            if(coveredFlag){
                do{
                    if(s[front] >= 'a' && s[front] <= 'z')
                        charMap_s[s[front] - 'a']--;
                    else    
                        charMap_s[s[front] - 'A' + 26]--;
                    front++;
                }while(isCovered(charMap_s, charMap_t));
                front -= 1;
                // 如果这是最小字串
                if(back - front + 1 < minWindowLength){
                    minWindowLength = back - front + 1;
                    min_front = front;
                }
                // 余下字符串迭代
                back++;
                front++;
            }
        }
        return minWindowLength == s.size() +1 ? "" : s.substr(min_front, minWindowLength);
    }
};

// 优化版代码
class Solution {
private:
    bool isCovered(const vector<int>& charMap_s, const vector<int>& charMap_t) {
        for (int i = 0; i < 52; i++) {
            if (charMap_s[i] < charMap_t[i]) {
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        string res;

        vector<int> charMap_s(52, 0);  // s 中字符的出现次数
        vector<int> charMap_t(52, 0);  // t 中字符的需要次数

        // 构建 t 中字符的频率映射
        for (int i = 0; i < t.size(); i++) {
            if (t[i] >= 'a' && t[i] <= 'z')
                charMap_t[t[i] - 'a']++;
            else    
                charMap_t[t[i] - 'A' + 26]++;
        }

        int front = 0, back = 0;
        int min_front = 0; 
        int minWindowLength = s.size() + 1;  // 初始最小窗口长度为大于字符串长度的数值

        while (back < s.size()) {
            // 扩展右边界
            if (s[back] >= 'a' && s[back] <= 'z')
                charMap_s[s[back] - 'a']++;
            else    
                charMap_s[s[back] - 'A' + 26]++;

            // 判断是否满足条件
            while (isCovered(charMap_s, charMap_t)) {
                // 如果满足条件，尝试更新最小窗口
                if (back - front + 1 < minWindowLength) {
                    minWindowLength = back - front + 1;
                    min_front = front;
                    // result = s.substr(front, minWindowLength);
                }

                // 收缩左边界
                if (s[front] >= 'a' && s[front] <= 'z')
                    charMap_s[s[front] - 'a']--;
                else    
                    charMap_s[s[front] - 'A' + 26]--;

                front++;
            }
            back++;
        }

        return minWindowLength == s.size() +1 ? "" : s.substr(min_front, minWindowLength);
    }
};

class Solution {
public:
    unordered_map <char, int> ori, cnt;

    bool check() {
        for (const auto &p: ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (const auto &c: t) {
            ++ori[c];
        }

        int l = 0, r = -1;
        int len = INT_MAX, ansL = -1, ansR = -1;

        while (r < int(s.size())) {
            if (ori.find(s[++r]) != ori.end()) {
                ++cnt[s[r]];
            }
            while (check() && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                if (ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]];
                }
                ++l;
            }
        }

        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};

// Solution
// 思路错误
class Solution {
private:
    bool isCovered(const vector<int>& charMap_s, const vector<int>& charMap_t){
        bool flag = true;
        for(int i = 0; i < 52; i++){
            if(charMap_t[i] > charMap_s[i]){
                flag = false;
                break;
            }
        }
        return flag;
    }
public:
    string minWindow(string s, string t) {
        vector<int> charMap_s(52, 0);
        vector<int> charMap_t(52, 0);

        for(int i = 0; i < t.size(); i++){
            if(t[i] >= 'a' && t[i] <= 'z')
                charMap_t[t[i] - 'a']++;
            else    
                charMap_t[t[i] - 'A' + 26]++;
        }

        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z')
                charMap_s[s[i] - 'a']++;
            else    
                charMap_s[s[i] - 'A' + 26]++;
        }

        // for(int front = 0, back = s.size()-1; ;){
        //     // 从头删除一个
        //     if(front)

        //     // 从尾删除一个

        // }
    }
};

int main(){

    // Solution s;

    cout << "Hello, world!" << endl;

    return 0;
}
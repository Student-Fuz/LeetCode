#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/delete-characters-to-make-fancy-string/?envType=daily-question&envId=2025-07-21

class Solution {
public:
    string makeFancyString(string s) {
        if(s.size() < 3) return s;
        string res(s.begin(), s.begin()+2);

        for(int i = 2; i < s.size(); i++){
            if(s[i] == res[res.size()-1] && s[i] == res[res.size()-2])
                continue;
            else
                res.push_back(s[i]);
        }
        return res;
    }
};

int main() {

    return 0;
}
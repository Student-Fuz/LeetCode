#include <bits/stdc++.h>
using namespace std;

// 链接：https://leetcode.cn/problems/find-common-characters/description/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> commonChars(26, 0);

        for(int i = 0; i < words[0].size(); i++){
            commonChars[words[0][i] - 'a']++;
        }

        for(int i = 0; i < words.size(); i++){
            vector<int> thisString(26, 0);
            for(int j = 0; j < words[i].size(); j++){
                thisString[words[i][j] - 'a']++;
            }

            for(int k = 0; k < 26; k++){
                commonChars[k] = min(commonChars[k], thisString[k]);
            }
        }

        vector<string> result;

        for(int i = 0; i < commonChars.size(); i++){
            for(int j = 0; j < commonChars[i]; j++){
                result.push_back(string(1, 'a' + i));
            }
        }

        return result;
    }
};

int main() {

    return 0;
}
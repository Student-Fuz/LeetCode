#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// 题目描述
// https://leetcode.cn/problems/restore-ip-addresses/

// Solution
// Solution
class Solution {
private:
    void backtracking(const string& s, int startIndex, vector<string>& result, vector<string>& IpAddress, string IpSection, int IpSecNum){
        if(startIndex == s.size()){
            if(IpAddress.size() == 4){
                string IpAddress_s;
                for(int i = 0; i < IpAddress.size(); i++)
                    IpAddress_s += IpAddress[i] + ".";
                IpAddress_s.pop_back();
                result.push_back(IpAddress_s);
            }
            return;
        }

        for(int i = startIndex; i < s.size(); i++){
            IpSection = s.substr(startIndex, i - startIndex + 1);

            if(valid(IpSection)){   // 如果IpSection合法
                IpSecNum += 1;
                if(IpAddress.size() < 5){
                    IpAddress.push_back(IpSection);
                    backtracking(s, i+1, result, IpAddress, "", IpSecNum);
                    IpAddress.pop_back();
                }

            }
        }

    }

    bool valid(string& IpSection){
        if(IpSection.size() == 0)
            return false;
        if(IpSection.size() > 3)
            return false;
        
        for(auto& num : IpSection)
            if(num < '0' || num >'9')
                return false;

        if(IpSection.size() != 1){
            if(IpSection[0] == '0')
                return false;
            int val = stoi(IpSection);
            if(val < 0 || val > 255)
                return false;
        }
        return true;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> IpAddress;

        backtracking(s, 0, result, IpAddress, "", 0);

        return result;
        
    }
};

int main(){

    Solution s;

    return 0;
}
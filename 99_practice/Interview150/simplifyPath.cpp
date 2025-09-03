#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/simplify-path/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> strs;
        string str = "";
        string r;

        for(const auto& p : path){
            if(p == '/'){
                if(str == "..") {
                    if(!strs.empty())
                        strs.pop_back();
                }
                else if(!str.empty() && str != "."){
                    strs.push_back(str);
                }
                str = "";
            }
            else{
                str.push_back(p);
            }
        }
        if(!str.empty()){
            if(str == "..") {
                if(!strs.empty())
                    strs.pop_back();
            }
            else if(str != "."){
                strs.push_back(str);
            }                
        } 

        if(strs.empty()) return "/";
        for(const auto& str : strs){
            r += "/" + str;
        }
        return r;
    }
};


class Solution {
public:
    string simplifyPath(string path) {
        string r;
        int dotCnt = 0;

        for(int i = 0; i < path.size(); i++){
            if(path[i] == '/'){
                if(dotCnt != 0){
                    if(dotCnt == 1){
                        r.pop_back();
                        r.pop_back();
                    } 
                    else if(dotCnt == 2){
                        if(r != "/"){
                            while(r.back() != '/') r.pop_back();
                            r.pop_back();
                        }else{
                            continue;
                        }
                        if(r != "/"){
                            while(r != "/" && r.back() != '/') r.pop_back();
                            r.pop_back();
                        }else{
                            continue;
                        }
                    }
                    dotCnt = 0;
                }
                if(!r.empty() && (r.back() == '/' || (i == path.size()-1 && r.back() != '/'))) continue;
            }
            else if(path[i] == '.') dotCnt++;
            r.push_back(path[i]);
        }

        return r;
    }
};

int main() {

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/minimum-number-of-people-to-teach/

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> p_friends;
        // language, num
        unordered_map<int, int> map;
        for(int i = 0; i < friendships.size(); i++){
            int a = friendships[i][0]-1, b = friendships[i][1]-1;
            bool canCom = false;
            for(auto& l_a : languages[a]){
                for(auto& l_b : languages[b]){
                    if(l_a == l_b){
                        canCom = true;
                        break;
                    } 
                }
            }
            if(!canCom){
                p_friends.insert(a);
                p_friends.insert(b);
            }     
        }
        for(auto f : p_friends){
            for(auto l : languages[f])
                map[l]++;
        }
        int target_l = 0;
        int maxTimes = 0;
        for(auto [l, t] : map){
            if(t > maxTimes){
                maxTimes = t;
                target_l = l;
            }
        }
        int r = 0;
        for(auto f : p_friends){
            bool can_l = false;
            for(auto l : languages[f]){
                if(l == target_l) can_l = true;
            }
            if(!can_l) r++;
        }
        return r;
    }
};

int main() {

    return 0;
}
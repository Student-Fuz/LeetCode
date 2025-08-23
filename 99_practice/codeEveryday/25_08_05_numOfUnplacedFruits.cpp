#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/fruits-into-baskets-ii/description/?envType=daily-question&envId=2025-08-05

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool> used(baskets.size(), false);
        int stored = 0;
        for(int i = 0; i < fruits.size(); i++){
            for(int j = 0; j < baskets.size(); j++){
                if((!used[j]) && fruits[i] <= baskets[j]){
                    used[j] = true;
                    stored++;
                    break;
                }
            }
        }
        return fruits.size() - stored;
    }
};



class MyCmp{
public:
    bool operator()(int& l, int& r){
        return l > r;
    }
};

// class Solution {
// public:
//     int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
//         sort(fruits.begin(), fruits.end(), MyCmp());
//         sort(baskets.begin(), baskets.end(), MyCmp());

//         int stored = 0;
//         int j = 0;
//         for(int i = 0; i < baskets.size(); i++){
//             for(; j < fruits.size(); j++){
//                 if(fruits[j] <= baskets[i]){
//                     stored++;
//                     j++;
//                     break;
//                 }
//             }
//             if(j == fruits.size()) break;
//         }

//         return baskets.size() - stored;
//     }
// };

int main() {

    vector<int> v = {1, 2, 3, 4, 5};
    sort(v.begin(), v.end(), MyCmp());

    for(auto& num : v)
        cout << num << endl;

    return 0;
}
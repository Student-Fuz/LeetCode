#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/compare-version-numbers/?envType=daily-question&envId=2025-09-22

class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t n1 = version1.size();
        size_t n2 = version2.size();

        size_t l1 = 0;
        size_t l2 = 0;
        
        size_t r1 = (version1.find_first_of('.') != std::string::npos ? version1.find_first_of('.') : n1);
        size_t r2 = (version2.find_first_of('.') != std::string::npos ? version2.find_first_of('.') : n2);
        cout << r1 << " " << r2 << endl;
    
        while(l1 < n1 || l2 < n2){
            int v1 = 0;
            int v2 = 0;
            if(l1 < n1) v1 = stoi(string(version1.begin()+l1, version1.begin()+r1));
            if(l2 < n2) v2 = stoi(string(version2.begin()+l2, version2.begin()+r2));
            if(v1 > v2) return 1;
            else if(v1 < v2) return -1;
            l1 = r1+1;
            l2 = r2+1;
            if(r1 != n1) r1 = version1.find_first_of('.', l1) != std::string::npos ? version1.find_first_of('.', l1) : n1;
            if(r2 != n2) r2 = version2.find_first_of('.', l2) != std::string::npos ? version2.find_first_of('.', l2) : n2;
        }
        return 0;
    }
};


// class Solution {
// public:
//     int compareVersion(string version1, string version2) {


//         size_t pt1Indx = version1.find('.');
//         size_t pt2Indx = version2.find('.');

//         int v1_0 = stoi(string(version1.begin(), version1.begin()+pt1Indx));
//         int v1_1 = stoi(string(version1.begin()+pt1Indx+1, version1.end()));

//         int v2_0 = stoi(string(version2.begin(), version2.begin()+pt2Indx));
//         int v2_1 = stoi(string(version2.begin()+pt2Indx+1, version2.end()));

//         if(v1_0 > v2_0) return 1;
//         else if(v1_0 < v2_0) return -1;
//         else{
//             if(v1_1 > v2_1) return 1;
//             else if(v1_1 < v2_1) return -1;
//         }
//         return 0;
//     }
// };

int main() {

    Solution s;

    s.compareVersion("1.0.1", "1.1");

    // string str = "123";

    // int a = stoi(string(str.begin(), str.begin()+3));

    // cout << a << endl;

    return 0;
}
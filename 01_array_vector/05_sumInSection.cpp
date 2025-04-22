#include <bits/stdc++.h>
using namespace std;

// // m1 暴力
// int main() {

//     int n;

//     cin >> n;

//     vector<int> nums(n);
//     for(int i = 0; i < n; i++){
//         cin >> nums[i];
//     }

//     // 不定行输入
//     int a, b;
//     int sum = 0;
//     while(cin >> a >> b){
//         sum = 0;
//         for(int i = a; i <= b; i++){
//             sum += nums[i];
//         }
//         cout << sum << endl;
//     }

//     return 0;
// }

// m2 前缀和
int main() {

    int n;

    cin >> n;

    vector<int> nums(n);
    vector<int> sums(n+1);
    sums[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        sums[i+1] = sums[i] + nums[i];
    }

    // 不定行输入
    int a, b;
    int sum = 0;
    while(cin >> a >> b){
        sum = 0;
        sum = sums[b+1] - sums[a]; 
        cout << sum << endl;
    }

    return 0;
}

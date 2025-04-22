#include <bits/stdc++.h>
using namespace std;

// m1 前缀和
int main() {

    int n, m;

    cin >> n >> m;

    vector<vector<int>> nums(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> nums[n][m];
        }
    }

    // 统计横向和
    vector<int> horizon(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            horizon[i] += nums[i][j];
        }
    }

    // 统计纵向和
    vector<int> vertical(m, 0);
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            vertical[i] += nums[i][j];
        }
    }

    int gap = INT_MAX;
    for(int i = 0; i < n; i++){
        
    }

    for(int j = 0; j < m; j++){

    }

    return 0;
}
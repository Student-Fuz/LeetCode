#include <bits/stdc++.h>
using namespace std;

// m1 前缀和
int main() {

    int n, m;

    cin >> n >> m;

    int sum = 0;
    vector<vector<int>> nums(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> nums[i][j];
            sum += nums[i][j];
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
            vertical[j] += nums[i][j];
        }
    }

    int minGap = INT_MAX;
    int horizontalCnt = 0;
    for(int i = 0; i < n; i++){
        horizontalCnt += horizon[i];
        minGap = min(minGap, abs(sum - horizontalCnt - horizontalCnt));
    }

    int verticalCnt = 0;
    for(int j = 0; j < m; j++){
        verticalCnt += vertical[j];
        minGap = min(minGap, abs(sum - verticalCnt - verticalCnt));
    }

    cout << minGap << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// 链接：https://kamacoder.com/problempage.php?pid=1065

// 思路：两个字符串

int main() {

    int num;
    string s;

    cin >> num;
    cin >> s;

    int size = s.size();
    s += s;

    s = string(s.begin() + size - num, s.begin() + size + size - num);

    cout << s << endl;

    return 0;
}
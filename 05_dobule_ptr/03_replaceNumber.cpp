#include <bits/stdc++.h>
using namespace std;

// 链接：https://kamacoder.com/problempage.php?pid=1064

// m1: 新开辟内存
int main() {

    string s;

    cin >> s;

    string new_s;

    for(int index; index < s.size(); index++){
        if('a' <= s[index] && s[index] <= 'z'){
            new_s.push_back(s[index]);
        }else{
            new_s += "number";
        }
    }

    cout << new_s << endl;

    return 0;
}

// m2: 
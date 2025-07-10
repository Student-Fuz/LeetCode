#include <bits/stdc++.h>
using namespace std;

// 链接：https://kamacoder.com/problempage.php?pid=1064

int main() {

    string s;

    cin >> s;

    string result;

    for(int i = 0; i < s.size(); i++){
        if('a' <= s[i]  && s[i] <= 'z'){
            result.push_back(s[i]);
        }
        else{
            result += "number";
        }
    }

    cout << result << endl;
    
    return 0;
}
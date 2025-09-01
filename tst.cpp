#include <bits/stdc++.h>
// #include<iostream>
using namespace std;

int main() {
    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        int n;
        cin >> n;
        int r = 1;
        vector<char> set;
        for(int j = 0; j < n; j++){
            char ch;
            cin >> ch;
            if(set.size() < 2){
                if(set.empty() || set[0] != ch)
                    set.push_back(ch);
            }
            else{
                if(set.size() == 2){
                    if(set[0] == ch || set[1] == ch){
                        continue;
                    }
                    else{
                        set.push_back(ch);
                        r++;
                    }
                }
                // size == 3
                else{
                    if(set[0] == ch){
                        set.erase(set.begin()+1);
                    }else if(set[1] == ch){
                        set.erase(set.begin());
                    }else if(set[2] != ch){
                        set = {set[2], ch};
                        r++;
                    }
                }

            }
        }
        cout << r << endl;
    }

    return 0;
}
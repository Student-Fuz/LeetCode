#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        // index; state
        queue<pair<int, char>> q;
        
        for(int i = 0; i < dominoes.size(); i++){
            if(dominoes[i] != '.'){
                q.push({i, dominoes[i]});
            }
        }

        // 层序遍历
        while(!q.empty()){
            int n = q.size();
            unordered_map<int, char> changed;
            for(int i = 0; i < n; i++){
                auto [node, state] = q.front();
                q.pop();
                if(state == 'R'){
                    if(node+1 < dominoes.size()){
                        int next = node+1;
                        if(dominoes[next] == '.'){
                            if(changed.count(next) == 0)
                                changed.insert({next, 'R'});
                            else
                                changed[next] = '.';
                        }
                    }
                }
                else{
                    if(node-1 >= 0){
                        int next = node-1;
                        if(dominoes[next] == '.'){
                            if(changed.count(next) == 0)
                                changed.insert({next, 'L'});
                            else
                                changed[next] = '.';
                        }
                    }
                }
            }
            for(auto [next, newState] : changed){
                if(newState != '.'){
                    dominoes[next] = newState;
                    q.push({next, newState});
                }
            }
            
        }
        return dominoes;
    }
};

int main() {

    return 0;
}
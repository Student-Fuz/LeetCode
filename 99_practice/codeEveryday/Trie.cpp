#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/implement-trie-prefix-tree/submissions/622313402/

class Trie {
private:
    vector<Trie*> children;
    bool isEnd;
public:
    Trie() : children(26), isEnd(false) {};
    
    void insert(string word) {
        Trie* node = this;
        for(int i = 0; i < word.size(); i++){
            int ch = word[i]-'a';
            if(node->children[ch] == nullptr){
                Trie* newNode = new Trie();
                node->children[ch] = newNode;
            }
            node = node->children[ch];
        }
        node->isEnd =  true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(int i = 0; i < word.size(); i++){
            int ch = word[i]-'a';
            if(node->children[ch] == nullptr) return false;
            node = node->children[ch];
        }
        if(node->isEnd == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(int i = 0; i < prefix.size(); i++){
            int ch = prefix[i]-'a';
            if(node->children[ch] == nullptr) return false;
            node = node->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {

    return 0;
}
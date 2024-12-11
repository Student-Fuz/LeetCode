#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <random>
#include <time>

using namespace std;

// 题目描述


// Solution
// try1
class RandomizedSet {
public:
    RandomizedSet() {
        // unordered_set<int> randomizedSet;
    }
    
    bool insert(int val) {
        if(randomizedSet.find(val) == randomizedSet.end()){
            randomizedSet.insert(val);
            return true;
        }
        else
            return false;
    }
    
    bool remove(int val) {
        if(randomizedSet.find(val) != randomizedSet.end()){
            randomizedSet.erase(val);
            return true;
        }
        else
            return false;
    }
    
    int getRandom() {
        // auto it = randomizedSet.begin();
        // for(int i = 0; i < rand()%randomizedSet.size(); i++)
        //     it++;
        // return *(it);

        randomizedSet.rehash(randomizedSet.size());
        // randomizedSet.rehash(100);
        return *randomizedSet.begin();
    }

private:
    unordered_set<int> randomizedSet;
};

class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if(val_map.find(val) != val_map.end())
            return false;
        else{
            val_map.insert({val, val_vec.size()});
            val_vec.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(val_map.find(val) == val_map.end())
            return false;
        else{
            val_vec[val_map[val]] = val_vec.back();
            val_vec.pop_back();
            val_map.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        int result;
        int removed_index = rand()%val_vec.size();
        result = val_vec[removed_index];
        val_vec[removed_index] = val_vec.back();
        return result;
    }

private:
    // key--val; value--index
    unordered_map<int, int> val_map = {};
    vector<int> val_vec = {};
};


int main(){

    // Solution s;
    
    return 0;
}
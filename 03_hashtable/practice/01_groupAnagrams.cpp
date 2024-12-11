#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

// 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

// try1---耗时较长
// 归结原因：使用std::unordered_map<char, int>或者std::multiset<char>作为键时，
// 计算键值的时间复杂度是O(|map|)或者O(|set|)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int group_index = 0;
        // string的char频率map
        std::unordered_map<char, int> str_map;
        // key-str_map; value-group_index
        std::unordered_map<std::unordered_map<char, int>, int, MapHash, MapEqual> strs_map;
        
        for(auto str : strs){
            for(char char_s : str){
                str_map[char_s]++;
            }
            if(strs_map.find(str_map) != strs_map.end()){
                result[strs_map[str_map]].push_back(str);
            }
            else{
                strs_map[str_map] = group_index++;
                result.push_back({str});
            }
            str_map.clear();
        }
        return result;
    }

    // 时间复杂度O(N)
    // 自定义哈希函数
    struct MapHash {
        std::size_t operator()(const std::unordered_map<char, int>& map) const {
            std::size_t hash_value = 0;
            for (const auto& [key, value] : map) {
                // Combine hash of key and value
                hash_value ^= std::hash<char>{}(key) ^ (std::hash<int>{}(value) << 1);
            }
            return hash_value;
        }
    };

    // 时间复杂度O(max(∣set1∣,∣set2∣))
    // 自定义相等比较函数
    struct MapEqual {
        bool operator()(const std::unordered_map<char, int>& map1,
                        const std::unordered_map<char, int>& map2) const {
            return map1 == map2; // 使用标准的 map 比较
        }
    };
};

// try2---耗时较长
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int group_index = 0;
        // string的char频率map
        std::multiset<char> str_set;
        // key-str_set; value-group_index
        std::unordered_map<std::multiset<char>, int, MapHash, MapEqual> strs_map;
        
        for(auto str : strs){
            for(char char_s : str){
                str_set.insert(char_s);
            }
            if(strs_map.find(str_set) != strs_map.end()){
                result[strs_map[str_set]].push_back(str);
            }
            else{
                strs_map[str_set] = group_index++;
                result.push_back({str});
            }
            str_set.clear();
        }
        return result;
    }

    // 时间复杂度O(N)
    // 自定义哈希函数
    struct MapHash {
        std::size_t operator()(const std::multiset<char>& set) const {
            std::size_t hash_value = 0;
            for (const auto& key : set) {
                // Combine hash of key and value
                hash_value ^= std::hash<char>{}(key);
            }
            return hash_value;
        }
    };

    // 时间复杂度O(max(∣set1∣,∣set2∣))
    // 自定义相等比较函数
    struct MapEqual {
        bool operator()(const std::multiset<char>& set1,
                        const std::multiset<char>& set2) const {
            return set1 == set2; // 使用标准的 set 比较
        }
    };
};

// 应该使用string、int等类型作为key
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<char> string_buffer;
        string str_sorted;
        int group_index = 0;
        // key-str_sorted; value-group_index
        std::unordered_map<string, int> strs_map;

        for(auto str : strs){
            for(char char_s : str){
                string_buffer.push_back(char_s);
            }
            std::sort(string_buffer.begin(), string_buffer.end());
            str_sorted.assign(string_buffer.begin(), string_buffer.end());

            if(strs_map.find(str_sorted) != strs_map.end())
                result[strs_map[str_sorted]].push_back(str);
            else{
                strs_map[str_sorted] = group_index++;
                result.push_back({str});
            }    
            string_buffer.clear();
            str_sorted.clear();
        }
        return result;
    }
};

int main(){

    Solution s;

    return 0;
}
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>

using namespace std;

// 给你一个字符串数组 words ，
// 请你找出所有在 words 的每个字符串中都出现的共用字符（包括重复字符），并以数组形式返回。你可以按 任意顺序 返回答案。
 

// 示例 1：

// 输入：words = ["bella","label","roller"]
// 输出：["e","l","l"]
// 示例 2：

// 输入：words = ["cool","lock","cook"]
// 输出：["c","o"]


int main(){

    cout << "Hello word!";
    cout << "a" + 1;

    return 0;
}

// // Version_1_0
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        std::array<int, 26> frequency_word_array;
        std::array<int, 26> frequency_array;
        std::vector<string> common_chars;

        // 第一个字符串
        for(int j = 0; j < words[0].size(); j++){
            frequency_array[words[0][j] - 'a'] += 1;
        }
            

        for(int i = 1; i < words.size(); i++){
            frequency_word_array.fill(0);
            for(int j = 0; j < words[i].size(); j++){
                frequency_word_array[words[i][j] - 'a'] += 1;
            }

            // 此处可优化，记录并更新频率不为0的字母索引
            for(int k = 0; k < 26; k++){
                frequency_array[k] = min(frequency_word_array[k], frequency_array[k]);
            }
            
        }
        
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < frequency_array[i]; j++){
                string s(1, 'a' + i);
                common_chars.push_back(s);
            }
        }
        return common_chars;
    }
};

// Version_1_1 超出内存限制
// class Solution {
// public:
//     vector<string> commonChars(vector<string>& words) {
//         std::unordered_map<char, int> frequency_word_table;
//         std::unordered_map<char, int> frequency_table;
//         std::vector<string> common_chars;

//         // 第一个字符串
//         for(int j = 0; j < words[0].size(); j++){
//             frequency_table[words[0][j]] += 1;
//         }
            

//         for(int i = 1; i < words.size(); i++){
//             frequency_word_table.clear();
//             for(int j = 0; j < words[i].size(); j++){
//                 frequency_word_table[words[i][j]] += 1;
//             }   

//             for(auto it = frequency_table.begin(); it != frequency_table.end();){
//                 // 若frequency_word_table中存在字母
//                 if(frequency_word_table.find(it->first) != frequency_word_table.end()){
//                     frequency_word_table[it->first] = 
//                     min(frequency_word_table[it->first], frequency_table[it->first]);
//                     ++it;
//                 }
//                 else{
//                     it = frequency_table.erase(it);
//                 }    
//             }      
//         }
        
//         for(auto pair : frequency_table){
//             string s(1, pair.first);
//             for(int i; i < pair.second; i++){
//                 common_chars.push_back(s);
//             }
            
//         }
//         return common_chars;
//     }
// };
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// // 题目描述
// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         int length = 0;

//         vector<int> unReached;
//         unordered_set<int> reached;

//         // key--current position; key--paths this way
//         unordered_map<string, vector<vector<string>>> cur = {{beginWord, {{beginWord}}}};
//         unordered_map<string, vector<vector<string>>> next;

//         vector<vector<string>> result_paths;

//         // 未到达的地点
//         for(int i = 0; i < wordList.size(); i++){
//             unReached.push_back(i);
//         }

//         do{
//             length++;
//             for(auto [curWord, paths] : cur){
//                 for(int j = 0; j < unReached.size(); j++){
//                     string next_word = wordList[unReached[j]];
//                     // 可以到达unReached[j]
//                     if(canConvert(curWord, next_word)){ 
//                         for(auto path : paths){
//                             path.push_back(next_word);
//                             next[next_word].push_back(path);
//                         }  
//                     }
//                 } 
//             }
//             int i = 0;
//             for(int j = 0; j < unReached.size(); j++){
//                 if(next.find(wordList[unReached[j]]) == next.end())
//                     unReached[i++] = unReached[j]; 
//             }

//             unReached.resize(i);

//             // 如果到了endWord
//             if(next.find(endWord) != next.end())  
//                 return next[endWord];
//             // 交换 cur 与 next   
//             cur.clear();
//             cur.swap(next);
//         }
//         while(!cur.empty());

//         return {};
//     }
    
//     bool canConvert(string s1, string s2){
//         if(s1.size() != s2.size())
//             return false;
//         int diffCharNum = 0;
//         for(int i = 0; i < s1.size(); i++){
//             if(s1[i] != s2[i])
//                 if(++diffCharNum > 1)
//                     return false;
//         }
//         if(diffCharNum == 1)
//             return true;
//         else
//             return false;
//     }
// };

// 存索引路径
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int length = 0;

        vector<int> unReached;
        unordered_set<int> reached;

        // key--current position; key--paths this way
        unordered_map<string, vector<vector<int>>> cur = {{beginWord, {{}}}};
        unordered_map<string, vector<vector<int>>> next;

        vector<vector<string>> result_paths;

        // 未到达的地点
        for(int i = 0; i < wordList.size(); i++){
            unReached.push_back(i);
        }

        do{
            length++;
            for(auto [curWord, paths] : cur){
                for(int j = 0; j < unReached.size(); j++){
                    string next_word = wordList[unReached[j]];
                    // 可以到达unReached[j]
                    if(canConvert(curWord, next_word)){ 
                        for(auto path : paths){
                            path.push_back(unReached[j]);
                            next[next_word].push_back(path);
                        }  
                    }
                } 
            }
            int i = 0;
            for(int j = 0; j < unReached.size(); j++){
                if(next.find(wordList[unReached[j]]) == next.end())
                    unReached[i++] = unReached[j]; 
            }

            unReached.resize(i);

            // 如果到了endWord
            if(next.find(endWord) != next.end()){
                for(auto& path :next[endWord]){
                    vector<string> path_s = {beginWord};
                    for(auto& step : path){
                        path_s.push_back(wordList[step]);
                    }
                    result_paths.push_back(path_s);
                }
                return result_paths;
            }

                    
            // 交换 cur 与 next   
            cur.clear();
            cur.swap(next);
        }
        while(!cur.empty());

        return {};
    }
    
    bool canConvert(string s1, string s2){
        if(s1.size() != s2.size())
            return false;
        int diffCharNum = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i])
                if(++diffCharNum > 1)
                    return false;
        }
        if(diffCharNum == 1)
            return true;
        else
            return false;
    }
};

// 正向广度优先搜索+反向深度搜索？

int main(){

    Solution s;

    string beginWord = "aaaaa", endWord = "ggggg";
    vector<string> wordList = {"aaaaa","caaaa","cbaaa","daaaa","dbaaa","eaaaa","ebaaa","faaaa","fbaaa","gaaaa","gbaaa","haaaa","hbaaa","iaaaa","ibaaa","jaaaa","jbaaa","kaaaa","kbaaa","laaaa","lbaaa","maaaa","mbaaa","naaaa","nbaaa","oaaaa","obaaa","paaaa","pbaaa","bbaaa","bbcaa","bbcba","bbdaa","bbdba","bbeaa","bbeba","bbfaa","bbfba","bbgaa","bbgba","bbhaa","bbhba","bbiaa","bbiba","bbjaa","bbjba","bbkaa","bbkba","bblaa","bblba","bbmaa","bbmba","bbnaa","bbnba","bboaa","bboba","bbpaa","bbpba","bbbba","abbba","acbba","dbbba","dcbba","ebbba","ecbba","fbbba","fcbba","gbbba","gcbba","hbbba","hcbba","ibbba","icbba","jbbba","jcbba","kbbba","kcbba","lbbba","lcbba","mbbba","mcbba","nbbba","ncbba","obbba","ocbba","pbbba","pcbba","ccbba","ccaba","ccaca","ccdba","ccdca","cceba","cceca","ccfba","ccfca","ccgba","ccgca","cchba","cchca","cciba","ccica","ccjba","ccjca","cckba","cckca","cclba","cclca","ccmba","ccmca","ccnba","ccnca","ccoba","ccoca","ccpba","ccpca","cccca","accca","adcca","bccca","bdcca","eccca","edcca","fccca","fdcca","gccca","gdcca","hccca","hdcca","iccca","idcca","jccca","jdcca","kccca","kdcca","lccca","ldcca","mccca","mdcca","nccca","ndcca","occca","odcca","pccca","pdcca","ddcca","ddaca","ddada","ddbca","ddbda","ddeca","ddeda","ddfca","ddfda","ddgca","ddgda","ddhca","ddhda","ddica","ddida","ddjca","ddjda","ddkca","ddkda","ddlca","ddlda","ddmca","ddmda","ddnca","ddnda","ddoca","ddoda","ddpca","ddpda","dddda","addda","aedda","bddda","bedda","cddda","cedda","fddda","fedda","gddda","gedda","hddda","hedda","iddda","iedda","jddda","jedda","kddda","kedda","lddda","ledda","mddda","medda","nddda","nedda","oddda","oedda","pddda","pedda","eedda","eeada","eeaea","eebda","eebea","eecda","eecea","eefda","eefea","eegda","eegea","eehda","eehea","eeida","eeiea","eejda","eejea","eekda","eekea","eelda","eelea","eemda","eemea","eenda","eenea","eeoda","eeoea","eepda","eepea","eeeea","ggggg","agggg","ahggg","bgggg","bhggg","cgggg","chggg","dgggg","dhggg","egggg","ehggg","fgggg","fhggg","igggg","ihggg","jgggg","jhggg","kgggg","khggg","lgggg","lhggg","mgggg","mhggg","ngggg","nhggg","ogggg","ohggg","pgggg","phggg","hhggg","hhagg","hhahg","hhbgg","hhbhg","hhcgg","hhchg","hhdgg","hhdhg","hhegg","hhehg","hhfgg","hhfhg","hhigg","hhihg","hhjgg","hhjhg","hhkgg","hhkhg","hhlgg","hhlhg","hhmgg","hhmhg","hhngg","hhnhg","hhogg","hhohg","hhpgg","hhphg","hhhhg","ahhhg","aihhg","bhhhg","bihhg","chhhg","cihhg","dhhhg","dihhg","ehhhg","eihhg","fhhhg","fihhg","ghhhg","gihhg","jhhhg","jihhg","khhhg","kihhg","lhhhg","lihhg","mhhhg","mihhg","nhhhg","nihhg","ohhhg","oihhg","phhhg","pihhg","iihhg","iiahg","iiaig","iibhg","iibig","iichg","iicig","iidhg","iidig","iiehg","iieig","iifhg","iifig","iighg","iigig","iijhg","iijig","iikhg","iikig","iilhg","iilig","iimhg","iimig","iinhg","iinig","iiohg","iioig","iiphg","iipig","iiiig","aiiig","ajiig","biiig","bjiig","ciiig","cjiig","diiig","djiig","eiiig","ejiig","fiiig","fjiig","giiig","gjiig","hiiig","hjiig","kiiig","kjiig","liiig","ljiig","miiig","mjiig","niiig","njiig","oiiig","ojiig","piiig","pjiig","jjiig","jjaig","jjajg","jjbig","jjbjg","jjcig","jjcjg","jjdig","jjdjg","jjeig","jjejg","jjfig","jjfjg","jjgig","jjgjg","jjhig","jjhjg","jjkig","jjkjg","jjlig","jjljg","jjmig","jjmjg","jjnig","jjnjg","jjoig","jjojg","jjpig","jjpjg","jjjjg","ajjjg","akjjg","bjjjg","bkjjg","cjjjg","ckjjg","djjjg","dkjjg","ejjjg","ekjjg","fjjjg","fkjjg","gjjjg","gkjjg","hjjjg","hkjjg","ijjjg","ikjjg","ljjjg","lkjjg","mjjjg","mkjjg","njjjg","nkjjg","ojjjg","okjjg","pjjjg","pkjjg","kkjjg","kkajg","kkakg","kkbjg","kkbkg","kkcjg","kkckg","kkdjg","kkdkg","kkejg","kkekg","kkfjg","kkfkg","kkgjg","kkgkg","kkhjg","kkhkg","kkijg","kkikg","kkljg","kklkg","kkmjg","kkmkg","kknjg","kknkg","kkojg","kkokg","kkpjg","kkpkg","kkkkg","ggggx","gggxx","ggxxx","gxxxx","xxxxx","xxxxy","xxxyy","xxyyy","xyyyy","yyyyy","yyyyw","yyyww","yywww","ywwww","wwwww","wwvww","wvvww","vvvww","vvvwz","avvwz","aavwz","aaawz","aaaaz"};

    for(auto path : s.findLadders(beginWord, endWord, wordList)){
        for(auto step : path)
            cout << step << " ";
        cout << endl;
    }


    cout << "hello, world ! ! !" << endl;
    return 0;
}
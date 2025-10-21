#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/design-spreadsheet/?envType=daily-question&envId=2025-09-22

class Spreadsheet {
private:
    vector<vector<int>> table;

public:
    Spreadsheet(int rows) {
        table = vector<vector<int>>(rows+1, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int row = stoi(string(cell.begin()+1, cell.end()));
        int col = cell[0]-'A';
        table[row][col] = value;
    }
    
    void resetCell(string cell) {
        int row = stoi(string(cell.begin()+1, cell.end()));
        int col = cell[0]-'A';
        table[row][col] = 0;
    }
    
    int getValue(string formula) {
        size_t eqInx = formula.find('=');
        size_t opInx = formula.find('+');
        string op1 = string(formula.begin()+eqInx+1, formula.begin()+opInx);
        string op2 = string(formula.begin()+opInx+1, formula.end());
        int opd1 = 0, opd2  = 0;
        if('A' <= op1[0] && op1[0] <= 'Z'){
            int row = stoi(string(op1.begin()+1, op1.end()));
            int col = op1[0]-'A';
            opd1 = table[row][col];
        }
        else{
            opd1 = stoi(op1);
        }
        if('A' <= op2[0] && op2[0] <= 'Z'){
            int row = stoi(string(op2.begin()+1, op2.end()));
            int col = op2[0]-'A';
            opd2 = table[row][col];
        }
        else{
            opd2 = stoi(op2);
        }
        return opd1 + opd2;
    }
};


int main() {

    return 0;
}
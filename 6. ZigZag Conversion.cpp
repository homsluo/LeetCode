//
// Created by homsl on 2019/6/12.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#if 0
string convert(const string& s, int row){
    string res;
    for(int i = 0; i < row; i++){
        int j = i;
        while(j < s.size()){
            res.push_back(s[j]);
            if(i != 0 && i != row-1){
                int temp = j + row-i+row-i-2;
                if(temp < s.size())
                    res.push_back(s[temp]);
            }
            j += row + row-2;
        }
    }
    return res;
}

int main(){
    string s = "PAYPALISHIRING";
    string str = convert(s, 3);
    for(auto v:str)
        cout << v;
}
#endif

string convert(const string& s, int row){
    if(s.size() <= row || row == 1)
        return s;
    vector<string>rows(min(row, int(s.size())));
    int currow = 0;
    bool down = false;

    for(char v:s){
        rows[currow] += v;
        if(currow == 0 || currow == row - 1)
            down = !down;
        currow += down ? 1 : -1;
    }

    string ret;
    for(string r : rows)
        ret += r;
    return ret;
}

int main(){
    string s = "PAYPALISHIRING";
    string str = convert(s, 3);
    for(auto v:str)
        cout << v;
}
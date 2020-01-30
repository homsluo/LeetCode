//
// Created by homsl on 2019/6/11.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string preProcess(const string& s){
    int n = s.size();
    string res;
    res.push_back('$');
    res.push_back('#');
    for(int i = 0; i < n; i++){
        res.push_back(s[i]);
        res.push_back('#');
    }
    res.push_back('^');
    return res;
}

string Manacher(const string& s){
    if(s.size() <= 1)
        return s;
    string str = preProcess(s);
    int n = str.size();
    vector<int> p(n, 0);
    int mx = 0, id = 0;
    for(int i = 1; i < n-1; i++){
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while(str[i - p[i]] == str[i + p[i]])
            p[i]++;
        if(i + p[i] > mx){
            mx = i + p[i];
            id = i;
        }
    }

    int maxLen = 0, index = 0;
    for(int i = 0; i < n-1; i++){
        if(p[i] > maxLen){
            maxLen = p[i];
            index = i;
        }
    }
    return s.substr((index - maxLen)/2, maxLen-1);
}

int main(){
    string s = "abcb";
    string ans = Manacher(s);
    for(auto v:ans)
        cout << v;
}

//--------------------------------------------------------------------------------
string longestPalindrome(string s) {
    if(s.empty())
        return "";
    int max = 0;
    string res;
    bool dp[s.size()][s.size()];
    for(int j = 0; j < s.size(); j++){
        for(int i = 0; i <= j; i++){
            dp[i][j] = s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1]);
            if(dp[i][j]){
                if(j-i+1 > max){
                    max = j-i+1;
                    res = s.substr(i, j-i+1);
                }
            }
        }
    }
    return res;
}
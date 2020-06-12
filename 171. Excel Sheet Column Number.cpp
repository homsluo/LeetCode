//
// Created by homsl on 2020/4/14.
//
int titleToNumber(string s) {
    unordered_map<char, int> map;
    for(char i = 'A'; i <= 'Z'; i++){
        map[i] = i-64;
    }
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        ans = ans*26 + map[s[i]];
    }
    return ans;
}
// --------------------------------
int titleToNumber(string s) {
    long long ans = 0;
    for(int i = 0; i < s.size(); i++){
        ans = ans*26 + s[i]-64;
    }
    return ans;
}

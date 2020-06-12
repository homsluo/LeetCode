//
// Created by homsl on 2020/4/13.
//
string convertToTitle(int n) {
    unordered_map<int, string> map;
    string ans;
    for(int i = 0; i < 26; i++){
        map[i] = char(i+65);
    }
    if(map.count(n))
        return map[--n];
    while(n){
        ans += map[(--n%26)];
        n /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

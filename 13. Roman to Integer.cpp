//
// Created by homsl on 2019/11/15.
//
int romanToInt(string s) {
    unordered_map<string, int> map = {{"CM", 900}, {"CD", 400}, {"XC", 90}, {"XL", 40}, {"IX", 9}, {"IV", 4},
                                      {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}};
    int res = 0;
    for(int i = 0; i < s.size();){
        if(i == s.size()-1){
            res += map[s.substr(i,1)];
            break;
        }
        if(map.find(s.substr(i, 2)) == map.end()){
            res += map[s.substr(i,1)];
            i++;
        }
        else{
            res += map[s.substr(i,2)];
            i += 2;
        }
    }
    return res;
}

// --------------------------------------------------
int romanToInt(string s) {
    unordered_map<char, int> map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    int res = map[s.back()];

    for(int i = s.size()-2; i >= 0; i--){
        if(map[s[i]] < map[s[i+1]])
            res -= map[s[i]];
        else
            res += map[s[i]];
    }
    return res;
}
// -------------------------------------------------------

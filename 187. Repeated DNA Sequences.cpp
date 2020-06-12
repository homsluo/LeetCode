//
// Created by homsl on 2020/5/4.
//
vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    if(s.size() < 10)
        return res;
    int left = 0;
    int right = 9;
    unordered_map<string, int> map;
    for(; right < s.size(); left++, right++){
        map[s.substr(left, 10)]++;
    }
    for(auto it:map){
        if(it.second > 1)
            res.push_back(it.first);
    }
    return res;
}

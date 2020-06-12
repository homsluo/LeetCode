//
// Created by homsl on 2020/5/13.
//
bool isIsomorphic(string s, string t) {
    if(s.empty() && t.empty())
        return true;
    if(s.size() != t.size())
        return false;
    unordered_map<char,char> map;
    for(int i = 0; i< s.size(); i++){
        if(map.count(s[i])){
            if(map[s[i]] != t[i])
                return false;
        }
        else{
            for(auto it:map){
                if(it.second == t[i])
                    return false;
            }
            map[s[i]] = t[i];
        }
    }
    return true;
}

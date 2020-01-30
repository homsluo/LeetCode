//
// Created by homsl on 2020/1/21.
//
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    if(strs.empty())
        return res;

    unordered_map<string, int> map;
    int count = 0;
    for(int i = 0; i < strs.size(); i++){
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        if(map.find(temp) == map.end()){
            vector<string> t = {strs[i]};
            res.push_back(t);
            map[temp] = count++;
        }
        else{
            res[map[temp]].push_back(strs[i]);
        }
    }
    return res;
}

//

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    if(strs.empty())
        return res;

    unordered_map<string, vector<string>> map;
    for(int i = 0; i < strs.size(); i++){
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        map[temp].push_back(strs[i]);
    }
    for(auto s:map)
        res.push_back(s.second);
    return res;
}

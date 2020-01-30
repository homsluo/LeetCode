//
// Created by homsl on 2019/11/20.
//
vector<string> combination(vector<string>& vec, string& str){
    vector<string> ret;
    if(vec.empty()){
        for(int i = 0; i < str.size(); i++){
            ret.push_back(str.substr(i,1));
        }
    }
    else{
        for(int i = 0; i < vec.size(); i++){
            for(int j = 0; j < str.size(); j++){
                ret.push_back(vec[i] + str.substr(j,1));
            }
        }
    }
    return ret;
}
vector<string> letterCombinations(string digits) {
    vector<string> res;
    if(digits.empty())
        return res;
    vector<string> PN = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for(int i = 0; i < digits.size(); i++){
        res = combination(res, PN[digits[i]-48]);
    }
    return res;
}

//--------------------------------------------------------------------------------------------------
// BackTracking
void backTracking(vector<vector<char>>& map, vector<string>& res, string& path, int idx, string& digits){
    if(idx == digits.size())
        res.push_back(path);
    else
        for(int i = 0; i < map[digits[idx]-'0'].size(); i++){
            path.push_back(map[digits[idx]-'0'][i]);
            backTracking(map, res, path, idx+1, digits);
            path.pop_back();
        }
}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    if(digits.empty())
        return res;
    vector<vector<char>> map = {{}, {}, {'a','b','c'}, {'d','e','f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'},
                                {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    string path;
    backTracking(map, res, path, 0, digits);
    return res;
}


//
// Created by homsl on 2020/6/4.
//
int shortestDistance(vector<string> &words, string &word1, string &word2) {
    unordered_map<string, vector<int>> m;
    for(int i = 0; i < words.size(); i++)
        m[words[i]].push_back(i);
    int res = words.size();
    for(int i = 0; i < m[word1].size(); i++){
        for(int j = 0; j < m[word2].size(); j++){
            res = min(res, abs(m[word1][i]-m[word2][j]));
        }
    }
    return res;
}

// ----------------------------------------------------------------------------------
int shortestDistance(vector<string> &words, string &word1, string &word2) {
    unordered_map<string, vector<int>> m;
    for(int i = 0; i < words.size(); i++)
        m[words[i]].push_back(i);
    int res = words.size();
    int i = 0;
    int j = 0;
    while(i < m[word1].size() && j < m[word2].size()){
        res = min(res, abs(m[word1][i]-m[word2][j]));
        m[word1][i] < m[word2][j] ? i++:j++;
    }
    return res;
}
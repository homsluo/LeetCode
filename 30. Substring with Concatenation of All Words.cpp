//
// Created by homsl on 2020/1/8.
//
vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    if(s.empty() || words.empty())
        return res;
    int m = words.size();
    int n = words[0].size();
    if(m*n > s.size())
        return res;
    unordered_map<string, int> map;
    for(string str : words){
        if(map.find(str) != map.end())
            map[str]++;
        else
            map[str] = 1;
    }
    unordered_map<string, int> copy;
    for(int i = 0; i <= s.size()-m*n; i++){
        int j = i;
        copy = map;
        while(j < i+m*n){
            if(copy.find(s.substr(j,n)) == copy.end() ||  copy[s.substr(j,n)] == 0)
                break;
            else
                copy[s.substr(j,n)]--;
            j += n;
        }
        if(j == i + m*n)
            res.push_back(i);
    }
    return res;
}

// imporoved

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    if(s.empty() || words.empty())
        return res;
    int m = words.size();
    int n = words[0].size();
    if(m*n > s.size())
        return res;
    unordered_map<string, int> map;
    for(string str : words)
        map[str]++;

    for(int i = 0; i < s.size()-m*n+1; i++){
        unordered_map<string, int> seen;
        int j = 0;
        for(; j < m; j++){
            string word = s.substr(i+j*n, n);
            if(map.find(word) != map.end()){
                seen[word]++;
                if(seen[word] > map[word])
                    break;
            }
            else
                break;
        }

        if(j == m)
            res.push_back(i);
    }
    return res;
}

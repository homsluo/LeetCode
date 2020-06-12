//
// Created by homsl on 2020/3/26.
//
vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<string> ans;
    unordered_set<string> set(wordDict.begin(), wordDict.end());
    unordered_map<string, vector<string>> used;

    ans = helper(s, set, used);
    return ans;
}

vector<string> helper(string s, unordered_set<string>& set, unordered_map<string, vector<string>>& used){
    if(used.count(s))
        return used[s];

    if(s.empty())
        return {};

    vector<string> res;
    for(int i = 1; i <= s.size(); i++){
        string sub = s.substr(0, i);
        vector<string> partRes;
        if(set.count(sub)){
            partRes = helper(s.substr(i), set, used);
            if(partRes.empty() && i == s.size())    //empty partRes:1.reach end; 2.no matching
                res.push_back(sub);
            else{
                for(string str:partRes)
                    res.push_back(sub + " " + str);
            }
        }
    }
    used[s] = res;
    return res;
}

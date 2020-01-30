//
// Created by homsl on 2019/9/11.
//
bool wordBreak(string s, vector<string>& wordDict){
    if(s.empty())
        return false;
    vector<bool> dp(s.size()+1, false);
    dp[0] = true;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j <= i; j++){
            if(dp[j]){
                string temp = s.substr(j, i-j+1);
                if(find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()){
                    if(i+1 < dp.size()){
                        dp[i+1] = true;
                        break;
                    }
                }
            }
        }
    }
    return dp[s.size()];
}

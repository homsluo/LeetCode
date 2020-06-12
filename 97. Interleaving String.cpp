//
// Created by homsl on 2020/2/15.
//
bool isInterleave(string s1, string s2, string s3) {
    if(s1.empty() && s2.empty() && s3.empty())
        return true;
    if(s1.size()+s2.size() != s3.size())
        return false;
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
    dp[0][0] = 1;
    for(int idx = 0; idx < s3.size(); idx++){
        for(int s1len = 0; s1len <= idx+1 && s1len <= s1.size(); s1len++){
            int s2len = idx+1-s1len;
            if(s2len > s2.size())
                continue;
            if((s1len > 0 && (s3[idx] == s1[s1len-1] && dp[s1len-1][s2len])) || (s2len > 0 && (s3[idx] == s2[s2len-1] && dp[s1len][s2len-1])))
                dp[s1len][s2len] = 1;
        }
    }
    return dp[s1.size()][s2.size()];
}

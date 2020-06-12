//
// Created by homsl on 2020/3/2.
//
int numDistinct(string s, string t) {
    if(t.empty())
        return 1;
    int s_len = s.size();
    int t_len = t.size();
    vector<vector<double>> dp(t_len+1, vector<double>(s_len+1, 0));
    dp[0][0] = 1;
    for(int i = 0; i <= s_len; i++)
        dp[0][i] = 1;

    for(int i = 1; i <= t_len; i++){
        for(int j = 1; j <= s_len; j++){
            if(s[j-1] == t[i-1])
                dp[i][j] = dp[i-1][j-1]+dp[i][j-1];
            else
                dp[i][j] = dp[i][j-1];
        }
    }
    return dp[t_len][s_len];
}

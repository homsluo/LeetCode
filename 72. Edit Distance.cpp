//
// Created by homsl on 2020/2/2.
//
int minDistance(string word1, string word2) {
    if(word1 == word2)
        return 0;
    vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1,0));
    for(int i = 0; i <= word1.size(); i++){
        for(int j = 0; j <= word2.size(); j++){
            if(i == 0 || j == 0){
                dp[i][j] = !i ? j : i;
            }
            else if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                // Insert: = dp[i][j-1]; Delete: = dp[i-1][j]; Replace: dp[i-1][j-1]
                dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
    }
    return dp[word1.size()][word2.size()];
}

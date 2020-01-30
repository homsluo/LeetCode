//
// Created by homsl on 2019/9/24.
//
int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size() < 1)
        return 0;
    if(matrix[0].size() < 1)
        return 0;
    int res = 0;
    for(int i = 0; i < matrix.size(); i++){
        vector<int> v(matrix[i].size(), 0);
        for(int j = i; j < matrix.size(); j++){
            for(int k = 0; k < matrix[j].size(); k++){
                if(matrix[j][k] == '1')
                    v[k]++;
            }
            res = max(res, getMaxSquare(v, j-i+1));
        }
    }
    return res;
}

int getMaxSquare(vector<int> v, int k){
    if(v.size() < k)
        return 0;
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == k)
            count++;
        else
            count = 0;
        if(count == k)
            return k*k;
    }
    return 0;
}

// -------------------------------------------------------------------------

int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size() < 1)
        return 0;
    if(matrix[0].size() < 1)
        return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    int res = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 || j == 0){
                dp[i][j] = matrix[i][j] - '0';
            }
            else if(matrix[i][j] == '1')
            {
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
            }
            res = max(res, dp[i][j]);
        }
    }
    return res*res;
}

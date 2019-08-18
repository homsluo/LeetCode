//
// Created by homsl on 2019/7/9.
//

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    if(m < 1 || obstacleGrid[0][0] == 1)
        return 0;
    int n = obstacleGrid[0].size();

    vector<vector<long>> ans = {m, vector<long>(n, 0)};
    ans[0][0] = 1;

    for(int i = 1; i < n; i++){
        if(obstacleGrid[0][i] == 1)
            ans[0][i] = 0;
        else
            ans[0][i] = ans[0][i-1];
    }
    for(int i = 1; i < m; i++){
        if(obstacleGrid[i][0] == 1)
            ans[i][0] = 0;
        else
            ans[i][0] = ans[i-1][0];
    }

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(obstacleGrid[i][j] == 1)
                ans[i][j] = 0;
            else
                ans[i][j] = ans[i-1][j] + ans[i][j-1];
        }
    }
    return ans[m-1][n-1];
}
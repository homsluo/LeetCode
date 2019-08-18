//
// Created by homsl on 2019/7/10.
//
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    if(m < 1)
        return 0;
    int n = grid[0].size();

    for(int i = 1; i < n; i++)
        grid[0][i] += grid[0][i-1];
    for(int i = 1; i < m; i++)
        grid[i][0] += grid[i-1][0];

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
    }
    return grid[m-1][n-1];
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    if(m < 1)
        return 0;
    int n = grid[0].size();

    vector<int> cur(m, grid[0][0]);
    for(int i = 1; i < m; i++)
        cur[i] = cur[i-1] + grid[i][0];
    for(int i = 1; i < n; i++){
        cur[0] += grid[0][i];
        for(int j = 1; j < m; j++){
            cur[j] = min(cur[j], cur[j-1]) + grid[j][i];
        }
    }
    return cur[m-1];
}

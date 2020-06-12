//
// Created by homsl on 2020/4/15.
//
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();
    vector<vector<int>> minHP(m+1, vector<int>(n+1, INT32_MAX));
    minHP[m-1][n] = 1;
    minHP[m][n-1] = 1;
    for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            minHP[i][j] = max(1, min(minHP[i][j+1], minHP[i+1][j])-dungeon[i][j]);
        }
    }
    return minHP[0][0];
}

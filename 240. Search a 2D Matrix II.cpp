//
// Created by homsl on 2020/5/31.
//
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // Start from right top corner
    // less: go 1 step left, greater: go 1 step downward
    if(matrix.empty() || matrix[0].empty())
        return false;
    int m = matrix.size();
    int n = matrix[0].size();
    if(target < matrix[0][0] || target > matrix[m-1][n-1])
        return false;
    int row = 0;
    int col = n-1;
    while(row < m && col >= 0){
        if(matrix[row][col] == target)
            return true;
        else  if(matrix[row][col] < target)
            row++;
        else
            col--;
    }
    return false;
}

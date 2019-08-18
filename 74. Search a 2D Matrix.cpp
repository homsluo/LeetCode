//
// Created by homsl on 2019/7/13.
//
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if(m < 1)
        return false;
    int n = matrix[0].size();
    if(n < 1)
        return false;
    if(target > matrix[m-1][n-1] || target < matrix[0][0])
        return false;

    for(int i = 0; i < m; i++){
        if(matrix[i][0] == target)
            return true;
        else if(matrix[i][0] > target){
            int row = i-1;
            for(int j = 1; j < n; j++)
                if(matrix[row][j] == target)
                    return true;
            return false;
        }
        else if(matrix[i][n-1] >= target){
            if(matrix[i][n-1] == target)
                return true;
            for(int j = 1; j < n; j++)
                if(matrix[i][j] == target)
                    return true;
            return false;
        }
    }
    if(target > matrix[m-1][0]){
        for(int j = 1; j < n; j++){
            if(target == matrix[m-1][j])
                return true;
            else
                return false;
        }
    }
    return false;
}

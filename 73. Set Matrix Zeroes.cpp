//
// Created by homsl on 2019/7/12.
//
void setZeroes(vector<vector<int>>& matrix) {
    unordered_map<int,int> rows;
    unordered_map<int,int> cols;
    int m = matrix.size();
    if(m < 1)
        return;
    int n = matrix[0].size();

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 0){
                rows[i] = 0;
                cols[j] = 0;
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if((rows.find(i) != rows.end()) || (cols.find(j) != cols.end()))
                matrix[i][j] = 0;
        }
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if(m < 1)
        return;
    int n = matrix[0].size();
    bool Colz = false;

    for(int i = 0; i < m; i++){
        if(matrix[i][0] == 0)
            Colz = true;
        for(int j = 1; j < n; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    if(matrix[0][0] == 0)
        for(int j = 1; j < n; j++)
            matrix[0][j] = 0;
    if(Colz)
        for(int i = 0; i < m; i++)
            matrix[i][0] = 0;
}


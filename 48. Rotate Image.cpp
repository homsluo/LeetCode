//
// Created by homsl on 2019/7/5.
//
void rotate(vector<vector<int>>& matrix) {
    int n = matrix[0].size();
    for(int row = 0; row <= (n-1)/2; row++)
        rtc(matrix, row, n);
}

void rtc(vector<vector<int>>& matrix, int row, int n){
    int temp1;
    int size = n-row*2;
    if(size == 1)
        return;
    int j = 0;
    for(int i = row, k = 0; k < size-1; i++,k++){
        temp1 = matrix[row][i];
        swap(matrix[i][n-1-row], temp1);
        swap(matrix[n-1-row][n-1-row-j], temp1);
        swap(matrix[n-1-row-j][row], temp1);
        matrix[row][i] = temp1;
        j++;
    }
}

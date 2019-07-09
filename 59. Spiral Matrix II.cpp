//
// Created by homsl on 2019/7/8.
//
vector<vector<int>> generateMatrix(int n) {
    if(n == 1){
        vector<vector<int>> res(1,{1});
        return res;
    }
    if(n == 0){
        vector<vector<int>> res;
        return res;
    }
    int wid = n, height = n-1;
    vector<vector<int>> res(n, vector<int>(n));
    n = n*n;

    int i = 0, j = 0, k = 1;
    while(k != n+1){
        for(int p = 0; p < wid && k != n+1; p++, j++)
            res[i][j] = k++;
        j--, wid--, i++;
        for(int p = 0; p < height && k != n+1; p++, i++)
            res[i][j] = k++;
        i--, height--, j--;
        for(int p = 0; p < wid && k != n+1; p++,j--)
            res[i][j] = k++;
        j++, wid--, i--;
        for(int p = 0; p < height && k != n+1; p++, i--)
            res[i][j] = k++;
        i++, height--, j++;
    }
    return res;
}

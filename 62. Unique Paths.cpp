//
// Created by homsl on 2019/7/8.
//
int uniquePaths(int m, int n){   // recursion
    if((m == 1) || (n == 1)){
        return 1;
    }
    return uniquePaths(m, n-1) + uniquePaths(m-1, n);
}

int uniquePaths(int m, int n){  // DP
    int arr[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if((i == 0) || (j == 0))
                arr[i][j] = 1;
            else
                arr[i][j] = arr[i-1][j]+arr[i][j-1];
        }
    }
    return arr[m-1][n-1];
}

int uniquePaths(int m, int n){  // Keep updating array
    int arr[n];
    arr[0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = 1; j < n; j++)
            arr[j] += arr[j-1];
    }
    return arr[n-1];
}
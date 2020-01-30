//
// Created by homsl on 2019/8/30.
//
void gameOfLife(vector<vector<int>>& board) {
    int m = board.size(), n = board[0].size();
    if(n < 1)
        return;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int count = -board[i][j];
            for(int p = max(i-1, 0); p < min(i+2, m); p++)
                for(int q = max(j-1, 0); q < min(j+2, n); q++)
                    count += board[p][q] & 1;
            if(count == 3 || (count == 2 && board[i][j]))
                board[i][j] |= 2;
        }
    }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            board[i][j] >>= 1;
}

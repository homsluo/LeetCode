//
// Created by homsl on 2020/3/17.
//
void solve(vector<vector<char>>& board) {
    int m = board.size();
    if(m == 0)
        return;
    const int n = board[0].size();

    function<void(int, int)> DFS = [&](int x, int y){
        if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O')
            return;
        board[x][y] = 'G';
        DFS(x-1, y);
        DFS(x, y-1);
        DFS(x+1, y);
        DFS(x, y+1);
    };

    for(int x = 0; x < m; x++){
        DFS(x, 0), DFS(x, n-1);
    }
    for(int y = 0; y < n; y++){
        DFS(0, y), DFS(m-1, y);
    }

    unordered_map<char, char> map = {{'G', 'O'}, {'O', 'X'}, {'X', 'X'}};
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            board[i][j] = map[board[i][j]];
    }
}

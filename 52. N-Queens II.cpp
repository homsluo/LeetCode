//
// Created by homsl on 2020/1/24.
//

class Solution {
private:
    vector<string> board;
    vector<int> col;
    vector<int> diag1;
    vector<int> diag2;
public:
    int totalNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        col = vector<int>(n, 0);
        diag1 = vector<int>(2*n-1, 0);
        diag2 = vector<int>(2*n-1, 0);
        int count = 0;
        nQueens(0, n, count);
        return count;
    }

    bool available(int x, int y, int n){
        return (!col[x] && !diag1[x+y] && !diag2[y-x+n-1]);
    }

    void updateBoard(int x, int y, int n, bool is_put){
        board[x][y] = is_put?'Q':'.';
        col[x] = is_put;
        diag1[x+y] = is_put;
        diag2[y-x+n-1] = is_put;
    }

    void nQueens(int y, int n, int& count){
        if(y == n){
            count++;
            return;
        }

        for(int x = 0; x < n; x++){
            if(!available(x, y, n))
                continue;
            updateBoard(x, y, n, true);
            nQueens(y+1, n, count);
            updateBoard(x, y, n, false);
        }
    }
};
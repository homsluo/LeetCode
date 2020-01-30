//
// Created by homsl on 2020/1/22.
//
class Solution {
private:
    vector<string> board;
    vector<int> col;
    vector<int> diag_1;
    vector<int> diag_2;
    vector<vector<string>> sol;
public:
    vector<vector<string>> solveNQueens(int n) {
        sol.clear();
        board = vector<string>(n, string(n, '.'));
        col = vector<int>(n, 0);
        diag_1 = vector<int>(2*n-1, 0);
        diag_2 = vector<int>(2*n-1, 0);

        nQueens(n, 0);
        return vector<vector<string>>(sol.begin(), sol.end());
    }

    bool available(int x, int y, int n){
        return (!col[x] && !diag_1[x+y] && !diag_2[y-x+n-1]);
    }

    void updateboard(int x, int y, int n, bool is_put){
        board[x][y] = is_put? 'Q' : '.';
        col[x] = is_put;
        diag_1[x+y] = is_put;
        diag_2[y-x+n-1] = is_put;
    }

    void nQueens(int n, int y){
        if(y == n){
            sol.push_back(board);
            return;
        }

        for(int x = 0; x < n; x++){
            if(!available(x, y, n))
                continue;
            updateboard(x, y, n, true);
            nQueens(n, y+1);
            updateboard(x, y, n, false);
        }
    }
};

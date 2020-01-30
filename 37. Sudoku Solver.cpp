//
// Created by homsl on 2020/1/9.
//
class Solution {
private:
    vector<vector<int>> row, col, box;
public:
    void solveSudoku(vector<vector<char>>& board) {
        row = vector<vector<int>>(9, vector<int>(9));
        col = vector<vector<int>>(9, vector<int>(9));
        box = vector<vector<int>>(9, vector<int>(9));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int n = board[i][j] - '0';
                    row[i][n-1] = 1;
                    col[j][n-1] = 1;
                    box[i/3*3+j/3][n-1] = 1;
                }
            }
        }

        fill(board, 0, 0);
    }

    bool fill(vector<vector<char>>& board, int x, int y){
        if(x > 8)
            return true;

        int ny = (y+1) % 9;
        int nx = (ny == 0) ? x+1 : x;

        if(board[x][y] != '.')
            return fill(board, nx, ny);

        int box_key = x/3*3+y/3;

        for(int i = 0; i < 9; i++){
            if(!row[x][i] && !col[y][i] && !box[box_key][i]){
                row[x][i] = 1;
                col[y][i] = 1;
                box[box_key][i] = 1;
                board[x][y] = char('0'+i+1);
                if(fill(board, nx, ny))
                    return true;
                board[x][y] = '.';
                box[box_key][i] = 0;
                col[y][i] = 0;
                row[x][i] = 0;
            }
        }

        return false;
    }
};

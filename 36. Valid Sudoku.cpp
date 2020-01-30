//
// Created by homsl on 2020/1/9.
//

bool isValidSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < 9; i += 3){
        for(int j = 0; j < 9; j += 3){
            if(!boxCheck(board, i, j)) return false;
        }
    }
    for(int i = 0; i < 9; i++){
        if(!rowCheck(board, i) || !colCheck(board, i)) return false;
    }
    return true;
}

bool rowCheck(vector<vector<char>>& board, int row){
    vector<int> temp(9,1);
    for(int i = 0; i < 9; i++){
        if(board[row][i] == '.') continue;
        else if(--temp[board[row][i]-'0'-1])
            return false;
    }
    return true;
}

bool colCheck(vector<vector<char>>& board, int col){
    vector<int> temp(9,1);
    for(int i = 0; i < 9; i++){
        if(board[i][col] == '.') continue;
        else if(--temp[board[i][col]-'0'-1])
            return false;
    }
    return true;
}

bool boxCheck(vector<vector<char>>& board, int row, int col){
    vector<int> temp(9,1);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[row+i][col+j] == '.') continue;
            else if(--temp[board[row+i][col+j]-'0'-1]) return false;
        }
    }
    return true;
}
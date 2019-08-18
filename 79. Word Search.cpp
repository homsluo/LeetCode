//
// Created by homsl on 2019/7/17.
//
bool exist(vector<vector<char>>& board, string word) {   // Memory limit exceeded
    bool res = false;
    int m = board.size();
    int n = board[0].size();
    if(word.size() > m*n)
        return res;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == word[0]){
                unordered_map<int,int> path;
                search(board, word, 1, i, j, res, path);
                if(res == true)
                    break;
            }
        }
    }
    return res;
}

void search(vector<vector<char>>& board, string word, int pos, int i, int j, bool& res, unordered_map<int,int>& path){
    if(path.find(i*board[0].size()+j) == path.end())
        path[i*board[0].size()+j] = 0;
    else
        return;
    if(pos == word.size()){
        res = true;
        return;
    }
    if(j > 0 && board[i][j-1] == word[pos])
        search(board, word, pos+1, i, j-1, res, path);
    if(i > 0 && board[i-1][j] == word[pos])
        search(board, word, pos+1, i-1, j, res, path);
    if(j < board[0].size()-1 && board[i][j+1] == word[pos])
        search(board, word, pos+1, i, j+1, res, path);
    if(i < board.size()-1 && board[i+1][j] == word[pos])
        search(board, word, pos+1, i+1, j, res, path);

    path.erase(i*board[0].size()+j);
    return;
}

//-------------------------------------------------------------------------------------------/

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    if(word.size() > m*n)
        return false;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(search(board, word, 0, i, j))
                return true;
    return false;
}

bool search(vector<vector<char>>& board, string word, int pos, int i, int j){
    if(pos == word.size())
        return true;
    if(i < 0 || i > board.size()-1 || j < 0 || j > board[0].size()-1)
        return false;
    if(word[pos] != board[i][j])
        return false;
    char temp = board[i][j];
    board[i][j] = '.';
    bool res = search(board, word, pos+1, i, j-1) || search(board, word, pos+1, i-1, j) || search(board, word, pos+1, i, j+1) || search(board, word, pos+1, i+1, j);
    board[i][j] = temp;
    return res;
}
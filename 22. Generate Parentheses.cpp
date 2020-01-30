//
// Created by homsl on 2019/12/28.
//

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0)
            return res;
        int open,close;
        open = close = n;
        string path;
        backTrack(res, path, open, close, n);
        return res;
    }

    void backTrack(vector<string>& res, string& path, int open, int close, int n){
        if(open > close)
            return;
        if(path.size() == 2*n){
            res.push_back(path);
            return;
        }

        for(int i = 0; i < 2; i++){
            if(open == 0)
                i = 1;
            if(!i){
                path += "(";
                backTrack(res, path, open-1, close, n);
            }
            else{
                path += ")";
                backTrack(res, path, open, close-1, n);
            }
            path.pop_back();
        }
        return;
    }
};
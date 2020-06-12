//
// Created by homsl on 2020/3/19.
//
public:
vector<vector<string>> partition(string s) {
    if(s.size() == 1 || s.empty())
        return {{s}};

    vector<vector<string>> ans;
    vector<string> path;
    DFS(s, ans, path, 0, s.size());
    return ans;
}

void DFS(string& s, vector<vector<string>>& ans, vector<string>& path, int start, int size){
    if(start == size)
        ans.push_back(path);

    for(int i = 1; i <= size-start; i++){
        string str = s.substr(start, i);
        if(isPalindrome(str)){
            path.push_back(str);
            DFS(s, ans, path, start+i, size);
            path.pop_back();
        }
    }
}

bool isPalindrome(string& s){
    if(s.size() == 1)
        return true;

    int left = 0;
    int right = s.size()-1;
    while(left < right){
        if(s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

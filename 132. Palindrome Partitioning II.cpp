//
// Created by homsl on 2020/3/19.
//
int minCut(string s) {
    if(s.empty() || s.size() == 1)
        return 0;

    int ans = INT32_MAX;
    vector<string> path;
    DFS(s, ans, path, 0, s.size());
    return ans;
}

void DFS(string& s, int& ans, vector<string>& path, int start, int size){
    if(start == size){
        int cut = path.size()-1;
        ans = min(cut, ans);
    }

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

//-------------------------------------------------------------------------------------------------------
int minCut(string s) {
    if(s.empty() || s.size() == 1)
        return 0;

    int n = s.size();
    vector<vector<int>> valid(n, vector<int>(n, 1));

    for(int len = 2; len <= n; len++){
        for(int i = 0, j = i+len-1; j < n; i++, j++){
            valid[i][j] = (s[i] == s[j]) && valid[i+1][j-1];
        }
    }

    vector<int> dp(n, n);
    for(int i = 0; i < n; i++){
        if(valid[0][i]){
            dp[i] = 0;
            continue;
        }
        for(int j = 0; j < i; j++){
            if(valid[j+1][i])
                dp[i] = min(dp[j]+1, dp[i]);
        }
    }
    return dp[n-1];
}

//--------------------------------------------------------------------------------------------------------------------------------
int minCut(string s) {
    if(s.empty() || s.size() == 1)
        return 0;

    int n = s.size();
    vector<int> dp(n, n);

    for(int mid = 0; mid < n; mid++){
        for(int odd = 0; odd <= 1; odd++){
            for(int i = mid, j = mid+odd; i >= 0 && j < n && s[i] == s[j]; i--, j++){
                dp[j] = min(dp[j], (i ? dp[i-1]+1 : 0));
            }
        }
    }
    return dp[n-1];
}

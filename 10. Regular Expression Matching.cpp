//
// Created by homsl on 2019/10/11.
//
bool isMatch(string s, string p) {
    if(p.size() == 0)
        return s.size() == 0;
    if(p.size() > 1 && p[1] == '*'){
        if(s.size() > 0 && (p[0] == s[0] || p[0] == '.'))
            return (isMatch(s.substr(1),p) || isMatch(s, p.substr(2)));   //s(a),p(a*);   s(a),p(a*a)
        else                                                         // p[0] == s[0]: match 1 time; match 0 time
            return isMatch(s, p.substr(2));   // p[0] != s[0] && p[0] != '.'
    }
    else{           // p[1] != '*'
        if(s.size() > 0 && (p[0] == s[0] || p[0] == '.'))
            return isMatch(s.substr(1),p.substr(1));
        else
            return false;
    }
}

//----------------------------------------------------------------------------------//
bool _isMatch(string s, string p, vector<vector<int>>& Mem) {       // Memoize
    if(p.size() == 0)
        return s.size() == 0;

    if (Mem[p.size()][s.size()] != 2)
        return Mem[p.size()][s.size()] == 1;

    if (p.size() > 1 && p[1] == '*') {
        if (s.size() > 0 && (p[0] == s[0] || p[0] == '.'))
            return Mem[p.size()][s.size()] = (_isMatch(s.substr(1), p, Mem) || _isMatch(s, p.substr(2), Mem));
        else
            return Mem[p.size()][s.size()] = _isMatch(s, p.substr(2), Mem);
    } else {
        if (s.size() > 0 && (p[0] == s[0] || p[0] == '.'))
            return Mem[p.size()][s.size()] = _isMatch(s.substr(1), p.substr(1), Mem);
        else
            return Mem[p.size()][s.size()] = false;
    }
}

bool isMatch(string s, string p) {
    vector<vector<int>> Mem(p.size()+1, vector<int>(s.size()+1, 2));
    return _isMatch(s, p, Mem);
}

// ------------------------------------------------------------------------------------------------------
// DP
// dp[i][j] =
//              1. dp[i-1][j-1]  if s[i-1] = p[j-1] || p[j-1] = '.'
//              2. dp[i][j-2]    if p[j] = '*', 0 occurancy
//                 dp[i-1][j]    if p[j] = '*' && (p[j-1] = s[i-1] || p[j-1] = '.')
//              3. false
bool isMatch(string s, string p) {
    vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
    dp[0][0] = true;

    for(int j = 2; j < p.size()+1; j++){
        if(p[j-1] == '*')
            dp[0][j] = dp[0][j-2];
    }

    for(int i = 1; i < s.size()+1; i++){
        for(int j = 1; j < p.size()+1; j++){
            if(p[j-1] == s[i-1] || p[j-1] == '.')
                dp[i][j] = dp[i-1][j-1];
            if(p[j-1] == '*')
                dp[i][j] = dp[i][j-2]|| ((p[j-2] == s[i-1] || p[j-2] == '.') && dp[i-1][j]);
        }
    }
    return dp[s.size()][p.size()];
}
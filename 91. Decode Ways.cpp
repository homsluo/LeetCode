//
// Created by homsl on 2019/9/3.
//
int numDecodings(string s) {  // Recursion O(n2)
    return s.empty() ? 0 : Decodings(0, s);
}

int Decodings(int beg, string& s){
    int n = s.size();
    if(beg == n)
        return 1;
    if(s[beg] == '0')
        return 0;
    int res = Decodings(beg+1, s);
    if(beg < n-1 && (s[beg] == '1'||(s[beg] == '2' && s[beg+1] < '7')))
        res += Decodings(beg+2, s);
    return res;
}

//----------------------------------------------------------------------------------

int numDecodings(string s) { // Memoization
    int n = s.size();
    vector<int> memo(n+1, -1);
    memo[n] = 1;
    return s.empty()?0:Decodings(0, s, memo);
}

int Decodings(int i, string& s, vector<int>& memo){
    if(memo[i] > -1)
        return memo[i];
    if(s[i] == '0')
        return memo[i] = 0;
    int res = Decodings(i+1, s, memo);
    int n = s.size();
    if(i < n-1 &&(s[i] == '1' || (s[i] == '2' && s[i+1] < '7')))
        res += Decodings(i+2, s, memo);
    return memo[i] = res;
}

//-------------------------------------------------------------------------------
int numDecodings(string s) { // DP, O(n)
    int n = s.size();
    vector<int> dp(n+1);
    dp[n] = 1;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == '0')
            dp[i] = 0;
        else{
            dp[i] = dp[i+1];
            if(i < n-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7')))
                dp[i] += dp[i+2];
        }
    }
    return s.empty()?0:dp[0];
}

//---------------------------------------------------------------------------------------
int numDecodings(string s) { // DP constant space
    int n = s.size();
    int p = 1, pp = 0, cur = 0;
    for(int i = n-1; i >= 0; i--){
        cur = s[i] == '0'? 0: p;
        if(i < n-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] < '7')))
            cur += pp;
        pp = p;
        p = cur;
    }
    return s.empty()?0:cur;
}
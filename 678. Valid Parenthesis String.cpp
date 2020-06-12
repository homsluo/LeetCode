//
// Created by homsl on 2020/4/16.
//
// Soulution1 Memoization O(n^3), Space: O(n^2)
class Solution {
private:
    vector<vector<int>> m;
public:
    bool checkValidString(string s) {
        if(s.empty())
            return true;
        int size = s.size();
        m = vector<vector<int>>(size, vector<int>(size, -1));
        return isValid(s, 0, size-1);
    }

    bool isValid(string& s, int i, int j){
        if(i > j)
            return 1;
        if(m[i][j] >= 0)
            return m[i][j];
        if(i == j)
            return m[i][j] = (s[i] == '*');

        if((s[i] == '(' || s[i] == '*')
           && (s[j] == ')' || s[j] == '*')
           && isValid(s, i+1, j-1))
            return m[i][j] = 1;

        for(int k = i; k < j; k++){
            if(isValid(s, i, k) && isValid(s, k+1, j))
                return m[i][j] = 1;
        }
        return m[i][j] = 0;
    }
};

// Solution 2 DP    O(n^3), O(n^2)
bool checkValidString(string s) {
    if(s.empty())
        return true;
    int size = s.size();
    vector<vector<int>> dp(size, vector<int>(size, 0));
    for(int i = 0; i < size; i++){
        dp[i][i] = (s[i] == '*');
    }
    for(int len = 2; len <= size; len++){
        for(int i = 0; i <= size-len; i++){
            int j = i+len-1;

            if((s[i] == '(' || s[i] == '*')
               && (s[j] == ')' || s[j] == '*')){
                if(len == 2 || dp[i+1][j-1]){   // Make sure when len=2, dp[i][j] is true
                    dp[i][j] = 1;
                    continue;
                }
            }

            for(int k = i; k < j; k++){
                if(dp[i][k] && dp[k+1][j]){
                    dp[i][j] = 1;
                    break;
                }
            }
        }
    }
    return dp[0][size-1];
}
// Solution3 Counting O(n), Space:O(1)
bool checkValidString(string s) {
    if(s.empty())
        return true;
    int min_op = 0; // min possible open'(', treat all '*' as ')'
    int max_op = 0; // max possible open'(', treat all '*' as '('

    // if min_op < 0, set to 0, treat wrong '*' as  ')'
    // if max_op < 0, return false since more ')' appeared
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(')
            min_op++;
        else
            min_op--;

        if(s[i] == ')')
            max_op--;
        else
            max_op++;

        if(min_op < 0)
            min_op = 0;
        if(max_op < 0)
            return false;
    }
    return (min_op == 0);
}
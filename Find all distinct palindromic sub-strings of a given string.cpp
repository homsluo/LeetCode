//
// Created by homsl on 2020/4/20.
//
/*Given a string of lowercase ASCII characters, find all distinct continuous palindromic sub-strings of it.
Examples:

Input: str = "abaaa"
Output:  Below are 5 palindrome sub-strings
a
aa
aaa
aba
b


Input: str = "geek"
Output:  Below are 4 palindrome sub-strings
e
ee
g
k
 */
void palindromeSubStrs(string s)
{
    map<string, int> map;
    int n = s.size();
    int R[2][n+1];

    s = '@' + s + '#';

    for(int j = 0; j < 1; j++){
        int rp = 0;
        R[j][0] = 0;
        int i = 1;
        while(i <= n){
            while(s[i-rp-1] == s[i+rp+j])
                rp++;
            R[j][i] = rp;
            int k = 1;
            while(R[j][i-k] != rp-k && k < rp){
                R[j][i+k] = min(R[j][i-k], rp-k);
                k++;
            }
            i += k;
            rp = max(rp-k, 0); // rp-k = R[j][i-k] or 0, can jump through some expansion in next loop
        }
    }

    s = s.substr(1, n);
    map[s.substr(0, 1)] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 1; j++)
            for(int rp = R[j][i]; rp > 0; rp--)
                map[s.substr(i-rp-1, 2*rp+j)] = 1;
        map[s.substr(i, 1)] = 1;        // Store every single character
    }

    for(auto it:map){
        cout << it.first << '\n';
    }
}

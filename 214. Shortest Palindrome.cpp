//
// Created by homsl on 2020/5/20.
//
string shortestPalindrome(string s) {
    // First reverse the string and put it in front of the original string, we can get a palindrome 100%
    // Then delete the prefix that same as suffix(can use KMP table) to get shortest prlindrome
    if(s.empty())
        return s;
    string temp = s;
    temp = reverse(temp.begin(), temp.end());
    if(temp == s)
        return s;
    s = s+'#'+temp;
    vector<int> kmp(s.size(),0);
    int j = 0;
    for(int i = 1; i < s.size(); i++){
        while(j > 0 && s[i] != s[j])
            j = kmp[j-1];
        if(s[i] == s[j]){
            kmp[i] = j+1;
            j++;
        }
    }
    temp = temp.substr(0, temp.size()-kmp.back());
    s = temp+s.substr(0, s.size()/2);
    return s;
}

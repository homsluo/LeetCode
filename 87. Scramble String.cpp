//
// Created by homsl on 2020/2/10.
//
bool isScramble(string s1, string s2) {
    if(s1.empty() || s2.empty() || s1.size() != s2.size())
        return false;
    if(s1.size() == 1)
        return (s1==s2)?true:false;
    string temp1 = s1;
    string temp2 = s2;
    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());
    if(temp1 != temp2)
        return false;

    for(int i = 1; i < s1.size(); i++){
        if((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) ||
           (isScramble(s1.substr(0, i), s2.substr(s2.size()-i, i)) && isScramble(s1.substr(i), s2.substr(0, s1.size()-i))))
            return true;
    }
    return false;
}

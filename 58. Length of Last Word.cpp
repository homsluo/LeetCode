//
// Created by homsl on 2020/1/28.
//
int lengthOfLastWord(string s) {
    if(s.empty())
        return 0;
    int i = s.size()-1;
    int count = 0;
    while(i >= 0 && s[i] == ' ')
        i--;
    while(i >= 0 && s[i] != ' '){
        count++;
        i--;
    }
    return count;
}

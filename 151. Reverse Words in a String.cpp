//
// Created by homsl on 2020/4/7.
//
string reverseWords(string s) {
    if(s.empty())
        return s;
    vector<string> words;
    int left = 0;
    int right = 0;
    while(left < s.size() && right < s.size()){
        string str;
        while(left < s.size() && s[left] == ' ')
            left++;
        right = left;
        while(right < s.size() && s[right] != ' ')
            right++;
        if(s[left] != ' ' && s[left] != '\0')
            words.push_back(s.substr(left, right-left));
        left = right;
    }
    string ans;
    for(int i = words.size()-1; i >= 0; i--){
        ans += ' '+words[i];
    }
    if(!ans.empty())
        return ans.substr(1);
    else
        return ans;
}

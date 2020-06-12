//
// Created by homsl on 2020/4/22.
//
string lastSubstring(string s) {
    if(s.size() < 2)
        return s;
    char maxchar = 'a';
    for(int i = 0; i < s.size(); i++)
        if(s[i] > maxchar)
            maxchar = s[i];
    unordered_set<int> cand;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == maxchar && (i == 0 || s[i-1] != maxchar))
            cand.insert(i);
    }
    int len = 1;
    while(cand.size() > 1){
        unordered_set<int> tbdel;
        maxchar = 'a';
        for(int num:cand){
            if(num+len >= s.size()){
                tbdel.insert(num);
                continue;
            }
            char curr = s[num+len];
            if(curr > maxchar)
                maxchar = curr;
        }
        for(int num:cand){
            if(num+len >= s.size())
                continue;
            char curr = s[num+len];
            if(curr != maxchar)
                tbdel.insert(num);
        }
        if(tbdel.size() >= cand.size())
            break;
        for(int num:tbdel)
            cand.erase(num);
        len++;
    }
    string ans;
    for(int num:cand)
        ans = s.substr(num);
    return ans;
}
//
// We use "j" to find a better starting index. If any is found, we use it to update "i"

// 1."i" is the starting index of the first substring
// 2."j" is the staring index of the second substring
// 3."k" is related to substring.length() (eg. "k" is substring.length()-1)

// Case 1 (s[i+k]==s[j+k]):
// -> If s.substr(i,k+1)==s.substr(j,k+1), we keep increasing k.
// Case 2 (s[i+k]<s[j+k]):
// -> If the second substring is larger, we update i with j. (The final answer is s.substr(i))
// Case 3 (s[i+k]>s[j+k]):
// -> If the second substring is smaller, we just change the starting index of the second string to j+k+1.
// Because s[j]~s[j+k] must be less than s[i], otherwise "i" will be updated by "j". So the next possible candidate is "j+k+1".
string lastSubstring(string s) {
    if(s.size() < 2)
        return s;
    int i = 0;
    int j = 1;
    int k = 0;
    while(j+k < s.size()){
        if(s[i+k] == s[j+k])
            k++;
        else if(s[i+k] < s[j+k]){
            i = j++;
            k = 0;
        }
        else{
            j += k+1;
            k = 0;
        }
    }
    return s.substr(i);
}

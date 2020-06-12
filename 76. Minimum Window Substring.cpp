//
// Created by homsl on 2020/2/5.
//
string minWindow(string s, string t) {
    if(s.empty() || t.empty())
        return "";
    unordered_map<char, int> tarstr;
    unordered_map<char, int> oristr;
    for(int i = 0; i < t.size(); i++){
        tarstr[t[i]]++;
    }
    int left = 0;
    int right = 0;
    string res;

    while(left < s.size() && !tarstr[s[left]])
        left++;
    if(left == s.size())
        return "";
    right = left;
    int count = 0;
    while(right < s.size()){
        if(tarstr[s[right]]){
            oristr[s[right]]++;
            if(oristr[s[right]] <= tarstr[s[right]])
                count++;
        }
        right++;

        while(count == t.size()){
            string temp = s.substr(left, (right-left));
            if(res.empty())
                res = temp;
            else
                res = (temp.size() < res.size())?temp:res;
            if(oristr[s[left]] == tarstr[s[left]])
                count--;
            oristr[s[left++]]--;
            while(left < s.size() && !tarstr[s[left]])
                left++;
        }
    }
    return res;
}

// Imporved

string minWindow(string s, string t) {
    if(s.empty() || t.empty())
        return "";
    vector<int> map(128, 0); // Ascii map
    for(auto i:t)
        map[i]++;
    int count = t.size(), left = 0, right = 0, dis = INT32_MAX, head = 0;
    while(right < s.size()){
        if(map[s[right++]]-- > 0)
            count--;
        while(count == 0){
            if((right-left) < dis){
                dis = right-left;
                head = left;
            }
            if(map[s[left++]]++ == 0)
                count++;
        }
    }
    return dis==INT32_MAX?"":s.substr(head, dis);
}

//
// Created by homsl on 2020/6/4.
//
int shortestDistance(vector<string> &words, string &word1, string &word2) {
    // Write your code here
    string lastword;
    int lastpos = -1;
    int res = words.size();
    for(int i = 0;i < words.size(); i++){
        if(words[i] == word1 || words[i] == word2){
            if((word1 == word2 && lastpos != -1) || (word1 != word2 && words[i] != lastword))
                res = min(res, i-lastpos);
            lastpos = i;
            lastword = words[i];
        }
    }
    return res;
}

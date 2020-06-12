//
// Created by homsl on 2020/6/3.
//
int shortestDistance(vector<string> &words, string &word1, string &word2) {
    // Write your code here
    string lastword;
    int count = 0;
    int res = words.size();
    for(string& word:words){
        count++;
        if(word == word1 || word == word2){
            if(!lastword.empty() && word != lastword)
                res = min(res, count);
            count++;
            lastword = word;
        }
    }
    return res;
}

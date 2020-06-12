//
// Created by homsl on 2020/3/7.
//
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(), wordList.end());
    if(words.find(endWord) == words.end())
        return 0;
    unordered_set<string> q1 = {beginWord};
    unordered_set<string> q2 = {endWord};

    int step = 0;
    while(!q1.empty() && !q2.empty()){
        step++;

        if(q1.size() > q2.size())
            swap(q1,q2);
        unordered_set<string> q;

        for(string str:q1){
            for(int i = 0; i < beginWord.size(); i++){
                char ch = str[i];
                for(char j = 'a'; j <= 'z'; j++){
                    str[i] = j;
                    if(q2.find(str) != q2.end())
                        return step+1;
                    if(words.find(str) == words.end())
                        continue;
                    q.insert(str);
                    words.erase(str);
                }
                str[i] = ch;
            }
        }
        swap(q,q1);
    }
    return 0;
}

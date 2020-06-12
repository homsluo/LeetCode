//
// Created by homsl on 2020/3/10.
//
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(), wordList.end());
    if(!words.count(endWord))
        return {};
    // Delete beg. end word for not repeat
    words.erase(beginWord);
    words.erase(endWord);

    const int l = beginWord.size();
    int step = 0; // Current step compare with stored steps
    bool found = false; // If found, go to DFS

    unordered_map<string, int> steps = {{beginWord, 1}};
    unordered_map<string, vector<string>> parents; // Store all parents for each node(Graph)
    queue<string> q;
    q.push(beginWord);

    vector<vector<string>> ans;

    while(!q.empty() && !found){
        step++;
        for(int size = q.size(); size > 0; size--){
            string p = q.front(); q.pop(); // Copy for later use
            string w = p; // Copy for generating new string based on current one
            for(int i = 0; i < l; i++){
                const char ch = w[i];
                for(int j = 'a'; j < 'z'; j++){
                    if(ch == j)
                        continue;
                    w[i] = j;
                    if(w == endWord){   // Find the endWord
                        parents[w].push_back(p);
                        found = true;
                    } else{             //Not the first time check w
                        // make sure the step is not larger than previous,
                        // then add to the parents
                        if(steps.count(w) && step < steps.at(w))
                            parents[w].push_back(p);
                    }

                    if(!words.count(w)) // Not the first time check w
                        continue;
                    // If first time check w
                    words.erase(w);
                    q.push(w);
                    steps[w] = steps.at(p)+1;
                    parents[w].push_back(p);
                }
                w[i] = ch;
            }
        }
    }

    if(found){ // Do DFS to construct answer
        vector<string> curr = {endWord};
        DFS(endWord, beginWord, parents, curr, ans);
    }

    return ans;
}

void DFS(string& word, string& beginWord, unordered_map<string, vector<string>>& parents, vector<string>& curr,
         vector<vector<string>>& ans){
    if(word == beginWord){
        ans.push_back(vector<string>(curr.rbegin(), curr.rend()));
        return;
    }

    for(string& p : parents.at(word)){
        curr.push_back(p);
        DFS(p, beginWord, parents, curr, ans);
        curr.pop_back();
    }
}

//---------------------------------------------------------------------------------------------------------------------------
// One way BFS
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> ans;
    unordered_set<string> words(wordList.begin(), wordList.end());
    if(!words.count(endWord))
        return ans;
    words.erase(endWord);

    const int l = beginWord.size();
    unordered_set<string> q{beginWord}, p;
    unordered_map<string, vector<string>> children;
    bool found = false;

    while(!q.empty()&&!found){
        for(const string& word:q)   // Delete all words appeared in queue in hashset
            words.erase(word);      // This will allow repeat for words except this and previous steps

        for(const string& word:q){
            string curr = word;
            for(int i = 0; i < l; i++){
                char ch = curr[i];
                for(int j = 'a'; j <= 'z'; j++){
                    curr[i] = j;
                    if(curr == endWord){
                        children[word].push_back(curr);
                        found = true;
                    } else if(words.count(curr) && !found){     // Words may repeat but hashset will eliminate all duplicates
                        p.insert(curr);
                        children[word].push_back(curr);
                    }
                }
                curr[i] = ch;
            }
        }
        swap(q, p);
        p.clear();
    }

    if(found){
        vector<string> path{beginWord};
        DFS(beginWord, endWord, children, path, ans);
    }
    return ans;
}

void DFS(string& word, string& endWord, unordered_map<string, vector<string>>& children, vector<string>& path,
         vector<vector<string>>& ans){
    if(word == endWord){
        ans.push_back(path);
        return;
    }

    for(string& p : children[word]){
        path.push_back(p);
        DFS(p, endWord, children, path, ans);
        path.pop_back();
    }
}

//--------------------------------------------------------------------------------------------------------------------
// Bidirectional BFS
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> ans;
    unordered_set<string> words(wordList.begin(), wordList.end());
    if(!words.count(endWord))
        return ans;

    int l = beginWord.size();

    unordered_set<string> q1{beginWord};
    unordered_set<string> q2{endWord};
    unordered_map<string, vector<string>> children;

    bool found = false;
    bool backward = false;

    while(!q1.empty() && !q2.empty() && !found){
        if(q1.size() > q2.size()){
            swap(q1,q2);
            backward = !backward;
        }

        for(const string& p:q1)
            words.erase(p);
        for(const string& p:q2)
            words.erase(p);

        unordered_set<string> q;

        for(const string& word:q1){
            string curr = word;
            for(int i = 0; i < l; i++){
                char ch = curr[i];
                for(int j = 'a'; j <= 'z'; j++){
                    curr[i] = j;

                    const string* parent = &word;
                    const string* child = &curr;
                    if(backward)
                        swap(parent, child);

                    if(q2.count(curr)){
                        children[*parent].push_back(*child);
                        found = true;
                    } else if(words.count(curr) && !found){
                        q.insert(curr);
                        children[*parent].push_back(*child);
                    }
                }
                curr[i] = ch;
            }
        }
        swap(q, q1);
    }

    if(found){
        vector<string> path{beginWord};
        DFS(beginWord, endWord, children, path, ans);
    }
    return ans;
}

void DFS(const string& word, const string& endWord, unordered_map<string, vector<string>>& children,
         vector<string>& path, vector<vector<string>>& ans){
    if(word == endWord){
        ans.push_back(path);
        return;
    }

    for(const string& p:children[word]){
        path.push_back(p);
        DFS(p, endWord, children, path, ans);
        path.pop_back();
    }
}
//
// Created by homsl on 2020/5/16.
//
class Trie {
private:
    bool isEnd;
    vector<Trie*> next;
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        next = vector<Trie*>(26);
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* cur = this;
        for(char ch:word){
            if(!cur->next[ch-97])
                cur->next[ch-97] = new Trie();
            cur = cur->next[ch-97];
        }
        cur->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* cur = this;
        for(char ch:word){
            if(cur->next[ch-97])
                cur = cur->next[ch-97];
            else
                return false;
        }
        return cur->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* cur = this;
        for(char ch:prefix){
            if(cur->next[ch-97])
                cur = cur->next[ch-97];
            else
                return false;
        }
        return true;
    }
};

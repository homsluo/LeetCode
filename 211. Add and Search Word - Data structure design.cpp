//
// Created by homsl on 2020/5/19.
//
class WordDictionary {
private:
    struct Trie{
    public:
        Trie* next[26];
        bool isEnd;
        Trie(): isEnd(false){
            for(auto& i:next)
                i = nullptr;
        }
    };
    Trie* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie* cur = root;
        for(char ch:word){
            if(!cur->next[ch-'a'])
                cur->next[ch-'a'] = new Trie();
            cur = cur->next[ch-'a'];
        }
        cur->isEnd = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchWord(word, root, 0);
    }

    bool searchWord(string& word, Trie* cur, int idx){
        if(idx == word.size())
            return cur->isEnd;
        if(word[idx] == '.'){
            for(auto& p:cur->next){
                if(p && searchWord(word, p, idx+1))
                    return true;
            }
            return false;
        }
        else{
            return cur->next[word[idx]-'a'] && searchWord(word, cur->next[word[idx]-'a'], idx+1);
        }
        return true;
    }
};

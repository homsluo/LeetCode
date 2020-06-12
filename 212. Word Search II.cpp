//
// Created by homsl on 2020/5/20.
//
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        struct Trie{
        public:
            const string* word;
            vector<Trie*> next;
            Trie():word(nullptr),next(26){}
            ~Trie(){
                for(auto& p:next)
                    delete p;
            }
        };
        Trie* root = new Trie();
        // Insert word into Trie
        for(const string& word:words){
            Trie* cur = root;
            for(char ch:word){
                if(!cur->next[ch-'a'])
                    cur->next[ch-'a'] = new Trie();
                cur = cur->next[ch-'a'];
            }
            cur->word = &word;
        }

        const int m = board.size();
        const int n = board[0].size();
        vector<string> ans;

        function<void(int, int, Trie*)> walk = [&](int x, int y, Trie* node){
            if(x < 0 || y < 0 || x == m || y == n || board[x][y] == '#')
                return;

            const char cur = board[x][y];

            Trie* next_node = node->next[cur-'a'];
            if(!next_node)
                return;
            if(next_node->word){
                ans.push_back(*next_node->word);
                next_node->word = nullptr;
            }
            //DFS
            board[x][y] = '#';
            walk(x, y-1, next_node);
            walk(x, y+1, next_node);
            walk(x-1, y, next_node);
            walk(x+1, y, next_node);
            board[x][y] = cur;
        };

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                walk(i, j, root);
            }
        }
        return ans;
    }
};

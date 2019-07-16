 class TrieNode{
      public : 
        string word; // there can be other variations, for example just a bool is_end will also work
        TrieNode *children[26];
        TrieNode(){
            for(int i = 0 ; i < 26 ; i++)
                children[i] = NULL;
            word = "";
        }
    };
    
    void BuildTrie(TrieNode *root , vector <string> words){
        TrieNode *cur = root;
        for(auto &word : words){
            cur = root;
            for(auto character : word){
                if(cur->children[character-'a'] == NULL){
                    cur->children[character-'a'] = new TrieNode();
                }
                cur = cur->children[character-'a'];
                
            }
            cur->word = word;
        }
    }

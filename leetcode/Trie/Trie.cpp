class Trie {
public:
    Trie *next[26]={nullptr};
    bool isEnd=false;
    /** Initialize your data structure here. */
    Trie() {
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *curr=this;
        for(char &c:word)
        {
            int index=c-'a';
            if(!curr->next[index])
            {
                curr->next[index]=new Trie();
            }
            curr=curr->next[index];
        }
        curr->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *curr=this;
        for(char &c:word)
        {
            int index=c-'a';
            if(!curr->next[index])
            {
                return false;
            }
            curr=curr->next[index];
        }
        return curr->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *curr=this;
        for(char &c:prefix)
        {
            int index=c-'a';
            if(!curr->next[index])
            {
                return false;
            }
            curr=curr->next[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
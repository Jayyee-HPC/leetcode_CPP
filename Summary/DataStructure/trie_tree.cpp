class Trie {
public:
    struct Node{    // data structure for node of trie
        bool isEnd = false;
        Node* children[26] = {NULL};
    };
    
    Node* root;  // root of the tree
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();  // initialising the root
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* curr = root;
        for(int i=0;i<word.size();i++) {
            int idx = word[i]-'a';
            if(curr->children[idx]==NULL) {
                curr->children[idx] = new Node();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* curr = root;
        for(int i=0;i<word.size();i++) {
            int idx = word[i]-'a';
            if(curr->children[idx]==NULL) {
                return false;
            }
            curr = curr->children[idx];
        }
        if(curr->isEnd == true) {
            return true;
        } else {
            return false;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i=0;i<prefix.size();i++) {
            int idx = prefix[i]-'a';
            if(curr->children[idx]==NULL) {
                return false;
            }
            curr = curr->children[idx];
        }
        if(curr)
            return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

struct Node {
    Node* links[26];
    bool flag = false;

    bool isContainKey(char key) { return links[key - 'a'] != NULL; }

    void put(char key, Node* node) { links[key - 'a'] = node; }

    Node* get(char key) { return links[key - 'a']; }

    void setEnd() { flag = true; }

    bool isEnd() { return flag; }
};

class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->isContainKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->isContainKey(word[i]))
            return false;
           node =  node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
         Node* node = root;
        for(int i=0;i<prefix.length();i++)
        {
            if(!node->isContainKey(prefix[i]))
            return false;
           node= node->get(prefix[i]);
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
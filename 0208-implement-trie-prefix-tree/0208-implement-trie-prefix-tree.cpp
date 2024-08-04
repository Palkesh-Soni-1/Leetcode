struct node{
    node* arr[26];
    bool flag = false;
    bool check(char ch)
    {
        return (arr[ch-'a']!=NULL);
    }
    void put(char ch, node* n)
    {
        arr[ch-'a'] = n;
    }
    node* get(char ch)
    {
        return arr[ch-'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie {
node* root;
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* no = root;
        for(int i=0;i<word.length();i++)
        {
            if(!no->check(word[i]))
            {
                no->put(word[i],new node());
            }
            no=no->get(word[i]);
        }
        no->setEnd();
    }
    
    bool search(string word) {
        node* no = root;
        for(int i=0;i<word.length();i++)
        {
            if(!no->check(word[i]))
            {
                return false;
            }
            no = no->get(word[i]);
        }
        return no->isEnd();
    }
    
    bool startsWith(string prefix) {
        node* no = root;
        for(int i=0;i<prefix.length();i++)
        {
            if(!(no->check(prefix[i])))
            {
                return false;
            }
            no = no->get(prefix[i]);
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
class Node {
public:
    bool isEnd;
    Node *child[26];

    Node(){
        this->isEnd = false;
         memset(child, NULL, sizeof(child));
    }
};

class Dictionary {
public:
    Node *root;

    Dictionary(){
        root = new Node();
    }

    void insert(string s){
        Node *temp = root;
        for(auto c: s){
            if(temp->child[c-'a'] == NULL){
                temp->child[c-'a'] = new Node();
            }
            temp = temp->child[c-'a'];
        }
        temp->isEnd = true;
    }

    bool search(string s, int i, Node *temp){
        if(i == s.length()){
            return temp->isEnd;
        }
        if(s[i] != '.'){
            if(temp->child[s[i] - 'a'] == NULL){
                return false;
            }
            return search(s, i+1, temp->child[s[i]-'a']);
        }
        for(int j=0;j<26;j++){
            if(temp->child[j] != NULL){
                if(search(s, i+1, temp->child[j])){
                    return true;
                }
            }
        }
        return false;
    }

    bool search(string s) {
        return search(s, 0, root);
    }
};


class WordDictionary {
public:
    Dictionary dict;
    
    WordDictionary() {
    }
    
    void addWord(string word) {
        dict.insert(word);
    }
    
    bool search(string word) {
        return dict.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
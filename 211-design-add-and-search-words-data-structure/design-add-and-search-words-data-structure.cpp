class Node {
    private:
    Node* links[26] = {nullptr};
    bool flag = false;

    public: 
    bool containsKey(char c) {
        return links[c-'a'] != nullptr;
    }
    void setKey(char c) {
        links[c-'a'] = new Node();
    }
    Node* getKey(char c) {
        return links[c-'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool getEnd() {
        return flag;
    }
};

class WordDictionary {
private: Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root; 

        for(int i = 0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) {
                node->setKey(word[i]);
            }
            node = node->getKey(word[i]);
        }

        node->setEnd();
    }

    bool dfs (string &word, int idx, Node* node) {
        if(idx == word.length()) return node->getEnd();

        if(word[idx] != '.' && !node->containsKey(word[idx])) return false;

        if(word[idx] == '.') {
            for(char c = 'a'; c <= 'z'; c++) {
                if(node->getKey(c)) {
                    if(dfs(word,idx+1,node->getKey(c))) {
                        return true;
                    }
                }
            }
        } else {
            return dfs(word,idx+1,node->getKey(word[idx]));
        }

        return false;
    }
    
    bool search(string word) {
        Node* node = root;
        return dfs(word,0,node);        
    }
};
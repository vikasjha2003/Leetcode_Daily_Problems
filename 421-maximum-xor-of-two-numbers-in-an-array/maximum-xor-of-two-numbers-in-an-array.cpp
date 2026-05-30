struct Node {
    Node* links[2] = {nullptr};
    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }
    Node* getKey(int bit) {
        return links[bit];
    }
    void setKey(int bit) {
        links[bit] = new Node();
    } 
};

struct Trie {
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;

        for(int i = 31; i>=0; i--) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) {
                node->setKey(bit);
            }
            node = node->getKey(bit);
        }
    }

    int getMax(int x) {
        Node* node = root;

        int curMax = 0;

        for(int i = 31; i>=0; i--) {
            int bit = (x >> i) & 1;
            if(node->containsKey(!bit)) {
                curMax += pow(2,i);
                node = node->getKey(!bit);
            } else {
                node = node->getKey(bit);
            }
        }

        return curMax;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();

        for(int a : nums) {
            trie->insert(a);
        }

        int res = 0;

        for(int x : nums) {
            res = max(res,trie->getMax(x));
        }

        return res;
    }
};
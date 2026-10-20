class TreeNode {
public:
    char value;
    map<char, TreeNode*> children;

    TreeNode(): value(), children() {}
    TreeNode(char v): value(v), children() {}
};

class WordDictionary {
    TreeNode* root;
public:
    WordDictionary() {
        root = new TreeNode();
    }
    
    void addWord(string word) {
        TreeNode* n = root;
        for (auto c : word) {
            if (n->children.contains(c)) {
                n = n->children[c];
            } else {
                TreeNode* nn = new TreeNode(c);
                n->children[c] = nn;
                n = nn;
            }
        }
        n->children[0] = new TreeNode();
    }
    
    bool search(string word) {
        return searchRec(word, root, 0);
    }

private:
    bool searchRec(const string& word, TreeNode* root, int i) {
        if (word[i] == '.') {
            for (auto [c, node] : root->children) {
                if (searchRec(word, node, i+1)) return true;
            }
        }
        if (word.size() == i) return root->children.contains(0);
        if (!root->children.contains(word[i])) return false;
        return searchRec(word, root->children[word[i]], i+1);
    }
};

class TreeNode {
public:
    char value;
    map<char, TreeNode*> children;

    TreeNode(): value(), children() {}
    TreeNode(char v): value(v), children() {}
};

class PrefixTree {
    TreeNode* root;
public:
    PrefixTree() {
        root = new TreeNode();
    }
    
    void insert(string word) {
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
        TreeNode* n = root;
        for (auto c : word) {
            if (!n->children.contains(c)) return false;
            n = n->children[c];
        }
        return n->children.contains(0);
    }
    
    bool startsWith(string prefix) {
        TreeNode* n = root;
        for (auto c : prefix) {
            if (!n->children.contains(c)) return false;
            n = n->children[c];
        }
        return true;
    }
};

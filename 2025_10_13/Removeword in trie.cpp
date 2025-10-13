#include <iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

     
    void insertUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';  
        TrieNode* child;

        // present
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    // ------------------- SEARCH -------------------
    bool searchUtil(TrieNode* root, string word) {
        // base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            return false;
        }

        // recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    // ------------------- REMOVE -------------------
    bool removeUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            // End of word
            if (root->isTerminal == false)
                return false; // word not found
            root->isTerminal = false;

            // check if node has no children
            for (int i = 0; i < 26; i++) {
                if (root->children[i] != NULL)
                    return false; // still has children
            }
            return true; // delete this node
        }

        int index = word[0] - 'A';
        TrieNode* child = root->children[index];

        if (child == NULL)
            return false; // word not found

        bool shouldDeleteChild = removeUtil(child, word.substr(1));

        if (shouldDeleteChild) {
            delete child;
            root->children[index] = NULL;

            // check if current node has any other children
            if (!root->isTerminal) {
                for (int i = 0; i < 26; i++) {
                    if (root->children[i] != NULL)
                        return false;
                }
                return true;
            }
        }
        return false;
    }

    void removeWord(string word) {
        removeUtil(root, word);
    }
};

// ------------------- MAIN FUNCTION -------------------
int main() {
    Trie *t = new Trie();

    t->insertWord("abcd");
    t->insertWord("abgl");
    t->insertWord("irfan");

    cout << "Before removal:\n";
    cout << "abcd: " << t->searchWord("abcd") << endl;
    cout << "abgl: " << t->searchWord("abgl") << endl;
    cout << "irfan: " << t->searchWord("irfan") << endl;

    t->removeWord("abcd");

    cout << "\nAfter removing 'abcd':\n";
    cout << "abcd: " << t->searchWord("abcd") << endl;
    cout << "abgl: " << t->searchWord("abgl") << endl;
    cout << "irfan: " << t->searchWord("irfan") << endl;

    return 0;
}

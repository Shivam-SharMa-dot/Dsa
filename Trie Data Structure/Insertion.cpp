#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertutill(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // assumption all word will be in caps
        int index = word[0] - 'a';
        TrieNode *child;
        // case if present

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // not present
        else
        { // agr present nhi h to create kro or aage bdho
            child = new TrieNode(word[0]);
            // phir aage bdho
            root->children[index] = child;
        }
        // recursion
        // passing next word except first at each call
        insertutill(child, word.substr(1));
    }
    void insert(string word)
    {
        insertutill(root, word);
    }
    bool searchutill(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        TrieNode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            return false;
        }
        return searchutill(child, word.substr(1));
    }
    bool search(string word)
    {
        return searchutill(root, word);
    }
    bool prefixutill(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return true;
        }
        TrieNode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            return false;
        }
        return prefixutill(child, word.substr(1));
    }
    bool startsWith(string prefix)
    {
        return prefixutill(root, prefix);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insert("arm");
    t->insert("time");
    t->insert("to");
    t->insert("die");
    cout << "present or not " << t->search("ar");
    return 0;
}
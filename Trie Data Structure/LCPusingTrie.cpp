// using trie data structure
#include<vector>
#include <iostream>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int childcount;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childcount = 0;
        isTerminal = false;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie(char ch)
    {
        root = new TrieNode(ch);
    }
    void insertutill(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            // present h to sirf aag bdho
            child = root->children[index];
        }
        else
        { // agr present nhi h to create kro or aage bdho
            child = new TrieNode(word[0]);
            // phir aage bdho
            root->childcount++;
            root->children[index] = child;
        }
        insertutill(child, word.substr(1));
    }
    void insert(string word)
    {
        insertutill(root, word);
    }
    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (root->childcount == 1)
            {
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }
            if (root->isTerminal)
            {
                break;
            }
        }
    }
};
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        Trie *t = new Trie('\0');
        // insert all word into trie
        for (int i = 0; i < strs.size(); i++)
        {
            t->insert(strs[i]);
        }

        string first = strs[0];
        string ans = "";

        t->lcp(first, ans);

        return ans;
    }
};
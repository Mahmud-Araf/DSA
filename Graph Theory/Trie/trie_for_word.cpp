// Trie implementation for word search and prefix search

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;
    TrieNode()
    {
        isEndOfWord = false;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(const string &word)
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            if (current->children.find(ch) == current->children.end())
            {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool search(const string &word)
    {
        TrieNode *current = root;
        for (char ch : word)
        {
            if (current->children.find(ch) == current->children.end())
            {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }

    bool startsWith(const string &prefix)
    {
        TrieNode *current = root;
        for (char ch : prefix)
        {
            if (current->children.find(ch) == current->children.end())
            {
                return false;
            }
            current = current->children[ch];
        }
        return true;
    }

    bool deleteWord(const string &word)
    {
        stack<pair<TrieNode *, char>> nodes;
        TrieNode *current = root;

        for (char ch : word)
        {
            if (current->children.find(ch) == current->children.end())
            {
                return false; 
            }
            nodes.push({current, ch});
            current = current->children[ch];
        }

        if (!current->isEndOfWord)
        {
            return false;
        }

        current->isEndOfWord = false;

        while (!nodes.empty())
        {
            auto [parent, ch] = nodes.top();
            nodes.pop();

            TrieNode *child = parent->children[ch];
            if (child->children.empty() && !child->isEndOfWord)
            {
                delete child;
                parent->children.erase(ch);
            }
            else
            {
                break;
            }
        }

        return true;
    }
};

int main()
{
}
#include <bits/stdc++.h>
using namespace std;

#define Alphabet_Size 26
struct Node
{
    Node *links[Alphabet_Size];
    bool flag; // flag : to check whether we reached the end of word or not
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEndofWord()
    {
        flag = true;
    }
    bool isEndofWord()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root; // taking node as virtual root to traverse Trie
        for (char ch : word)
        {
            if (!node->containsKey(ch))
                node->put(ch, new Node());
            node = node->get(ch); // passing the refrence node of 'ch' to 'node', similar to node->next in SLL
        }
        node->setEndofWord();
    }

    bool search(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containsKey(ch))
            {
                return false;
            }
            node = node->get(ch);
        }
        return node->isEndofWord();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (char ch : prefix)
        {
            if (!node->containsKey(ch))
            {
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
};

/*
#include <bits/stdc++.h>

struct Node
{
    Node *links[26];
    int countW=0;
    int countP=0;
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
};
class Trie{
    private: Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string &word){
        Node* node = root;
        for(char ch: word){
            if(!node->containsKey(ch)){
                node->put(ch,new Node());
            }
            node = node->get(ch);
            node->countP++;
        }
        node->countW++;
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(char ch: word){
            if(!node->containsKey(ch))
                return 0;
            node = node->get(ch);
        }
        return node->countW;
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(char ch: word){
            if(!node->containsKey(ch))
                return 0;
            node = node->get(ch);
        }
        return node->countP;
    }

    void erase(string &word){
        Node* node = root;
        for(char ch: word){
            if(node->containsKey(ch)){
                node = node->get(ch);
                node->countP--;
            }
            else return;
        }
        node->countW--;
    }
};

*/
#include <iostream>
#include "trieNode.h"
using namespace std;

class Trie{
    private:
    trieNode *root;
    public:
    Trie(){
        root = new trieNode('\0');
    }
    ~Trie(){
        delete root;
    }
    private:
    trieNode* insertWord(trieNode* node,string word){
        //base case
        if (word.size() == 0){
            node->isTerminal = true;
            return node;
        }

        int index = word[0] - 'a';
        if (!node->children[index]){
            node->children[index] = new trieNode(word[0]);
        }
        node->children[index]= insertWord(node->children[index], word.substr(1));
        return node;
    }
    public:
    void insertWord(string word){
        this->root = insertWord(this->root,word);
    }

    private:
    trieNode *removeWord(trieNode *node, string word){
        //base case
        if (word.size() == 0){
            node->isTerminal = false;
            return node;
        }

        trieNode* child;
        int index = word[0] - 'a';
        if (node->children[index]){
           child = node->children[index];
        }
        else {
            return node;
        } 
        node->children[index] = removeWord(child, word.substr(1));
        return node;
    }

    public:
    void removeWord(string word){
        this->root = removeWord(this->root, word);
    }

    bool isPresent(string word){
        
    }
    

};
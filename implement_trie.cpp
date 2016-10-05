#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class TrieNode {
public:
    // Initialize data structure here.
    char val;
    vector<TrieNode*> neighbors;
    TrieNode()=default;
    TrieNode(char x):val(x){}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* a=root;
        int i,k,flag=0,temp;
        for(i=0;i<word.size();i++){
            temp=root->neighbors.size();
            if(temp==0) flag=1;
            else{
                for(k=0;k<temp;k++){
                    if(root->neighbors[k]->val==word[i]){
                        root=root->neighbors[k];
                        break;
                    }
                }
                if(k==temp) flag=1;
            }
            if(flag){
                while(i<word.size()){
                    TrieNode* p=new TrieNode(word[i]);
                    root->neighbors.push_back(p);
                    root=root->neighbors.back();
                    i++;
                }
                break;
            }
        }
        for(k=0;k<root->neighbors.size();k++){
            if(root->neighbors[k]->val=='#') break;
        }
        if(k==root->neighbors.size()){
            TrieNode* p=new TrieNode('#');
            root->neighbors.push_back(p);
        }
        root=a;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int i,k,temp;
        TrieNode* a=root;
        for(i=0;i<word.size();i++){
            temp=root->neighbors.size();
            if(temp==0){
                root=a;
                return 0;
            }
            for(k=0;k<temp;k++){
                if(root->neighbors[k]->val==word[i]){
                    root=root->neighbors[k];
                    break;
                }
            }
            if(k==temp){
                root=a;
                return 0;
            }
        }
        for(k=0;k<root->neighbors.size();k++){
            if(root->neighbors[k]->val=='#') break;
        }
        if(k==root->neighbors.size()){
            root=a;
            return 0;
        }
        root=a;
        return 1;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int i,k,temp;
        TrieNode* a=root;
        for(i=0;i<prefix.size();i++){
            temp=root->neighbors.size();
            if(temp==0){
                root=a;
                return 0;
            }
            for(k=0;k<temp;k++){
                if(root->neighbors[k]->val==prefix[i]){
                    root=root->neighbors[k];
                    break;
                }
            }
            if(k==temp){
                root=a;
                return 0;
            }
        }
        root=a;
        return 1;
    }

private:
    TrieNode* root;
};


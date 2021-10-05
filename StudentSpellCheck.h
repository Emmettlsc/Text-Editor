#ifndef STUDENTSPELLCHECK_H_
#define STUDENTSPELLCHECK_H_

#include "SpellCheck.h"



class StudentSpellCheck : public SpellCheck {
public:
    StudentSpellCheck() {
        root = new TrieNode;
        initializeTrieNode(root);
    }
    virtual ~StudentSpellCheck();
    bool load(std::string dict_file);
    bool spellCheck(std::string word, int maxSuggestions, std::vector<std::string>& suggestions);
    void spellCheckLine(const std::string& line, std::vector<Position>& problems);

private:
    struct TrieNode{
        TrieNode* children[27];  //a-z + apostrophe
        bool wordend;
    };
    TrieNode* root;
    
    void insertwordintotrie (TrieNode* root, std::string insert);
    void initializeTrieNode (TrieNode* target); //sets all children to null ptr
    bool searchTrie(std::string check); //returns true if word found
    void freeNodes(TrieNode* killmychildren);   //deletes dynamically allocated memory
    void getsuggestions(std::string word, int max_suggestions, std::vector<std::string>& suggestions);  //adds suggestions to vector
};

#endif  // STUDENTSPELLCHECK_H_

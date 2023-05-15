#include "Trie.h"
class Autocomplete
{
public:
    Autocomplete();
    Trie *myTrie;
    std::vector<std::string> getSuggestions(std::string partialWord); // return the known words that start with partialWord
    void insert(std::string word);                                    // add a word to the known words
    void list(Trie *node, std::string curr, std::vector<std::string> &sugg);
};
#include "Autocomplete.h"

Autocomplete::Autocomplete()
{
    myTrie = new Trie;
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord)
{
    std::vector<std::string> suggs;
    std::string curr;
    auto dummy = myTrie;

    for (char c : partialWord)
    {
        dummy = dummy->children[c - 'a'];

        if (dummy == NULL)
        {
            return suggs;
        }

        curr.push_back(c);
    }

    list(dummy, curr, suggs);

    return suggs;
}

void Autocomplete::list(Trie *node, std::string curr, std::vector<std::string> &suggs)
{
    if (node == NULL)
    {
        return;
    }

    if (node->isWord == true)
    {
        suggs.push_back(curr);
    }

    for (int i = 0; i < 26; i++)
    {
        list(node->children[i], curr + char(i + 97), suggs);
    }
}

void Autocomplete::insert(std::string word)
{
    auto dummy = myTrie;

    for (char c : word)
    {
        if (!dummy->children[c - 'a'])
        {
            dummy->children[c - 'a'] = new Trie;
        }

        dummy = dummy->children[c - 'a'];
    }

    dummy->isWord = true;
}
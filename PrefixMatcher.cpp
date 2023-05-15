#include "PrefixMatcher.h"

PrefixMatcher::PrefixMatcher()
{
    myTrie = new Trie;
}

int PrefixMatcher::selectRouter(std::string networkAddress)
{
    auto dummy = myTrie;
    std::string curr;

    for (char c : networkAddress)
    {
        curr.push_back(c);
        dummy = dummy->children[c - '0'];
    }

    while (routerNums.count(curr) == 0)
    {
        if (dummy->children[0] != NULL)
        {
            dummy = dummy->children[0];
            curr.push_back('0');
        }
        else
        {
            dummy = dummy->children[1];
            curr.push_back('1');
        }
    }

    return routerNums[curr];
}

void PrefixMatcher::insert(std::string address, int routerNumber)
{
    auto dummy = myTrie;
    std::string curr;

    for (char c : address)
    {
        if (!dummy->children[c - '0'])
        {
            dummy->children[c - '0'] = new Trie;
        }

        curr.push_back(c);
        dummy = dummy->children[c - '0'];
    }

    routerNums[curr] = routerNumber;
}
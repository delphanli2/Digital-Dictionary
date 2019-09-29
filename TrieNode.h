// File name: TrieNode.h
// Author: Zexin Li
// Userid: liz27
// Email: zexin.li@vanderbilt.edu
// Class: session1
// Assignment Number: PA9
// Honor Statement: I do this without unauthorized aid
// Description: This is the TrieNode interface
// Last Changed: 2018/04/18

#ifndef PROJECT9_TRIENODE_H
#define PROJECT9_TRIENODE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <cassert>

class TrieNode {

private:
    char myLetter;
    bool endOfWord;
    TrieNode* children [26];
    typedef TrieNode* TrieNodePtr;

public:
//constructor
    TrieNode(char c, bool b);

//copy constructor
    TrieNode(const TrieNode &rhs);

//destructor
    ~TrieNode();

//Assignment operator
    const TrieNode &operator=(const TrieNode &rhs);

/* insert
 * This method Insert str starting with the given TrieNode. Create new TrieNodes
as needed and be sure to set the boolean flag on the last node to
true.
 *
 * pre:  A string to be inserted is passed in as parameter
 * post: The string is added starting with the given TrieNode
 */
    void insert(const std::string &str);

/* isWord
 * This method returns true if str is in the sub-Trie starting at the given TrieNode,
else returns false
 *
 * pre:  A string is received as parameter
 * post:  Returns true if str is in the sub-Trie starting at the given TrieNode,
else returns false
 */
    bool isWord(const std::string &str) const;

/* isPrefix
 * This method returns true if pre is a prefix of a word in the sub-Trie starting at
the given TrieNode, else returns false
 *
 * pre:  A string is received as parameter
 * post:  returns true if pre is a prefix of a word in the sub-Trie starting at
the given TrieNode, else returns false
 */
    bool isPrefix(const std::string &pre) const;

/* print
 Prints all words starting at the given TrieNode. The parameter
string str stores the letters of all previous TrieNode objects up to
the node currently being processed
 *
 * pre:  The TrieNode exists
 * post: Print out all the words starting at the given TrieNode
 */
    void print(const std::string &str) const;



};






















#endif //PROJECT9_TRIENODE_H

// File name: Trie.h
// Author: Zexin Li
// Userid: liz27
// Email: zexin.li@vanderbilt.edu
// Class: session1
// Assignment Number: PA9
// Honor Statement: I do this without unauthorized aid
// Description: This file is the interface of Trie class
// Last Changed: 2018/04/18

#ifndef PROJECT9_TRIE_H
#define PROJECT9_TRIE_H
#include <iostream>
#include <string>
#include <fstream>
#include "TrieNode.h"
//constructor
class Trie{
private:
    size_t myCount;
    TrieNode rootNode;


public:
    //constructor
    Trie();

    /* insert
 * This method Insert str into the Trie object. Create new TrieNodes
as needed and be sure to set the boolean flag on the last node to
true.
 *
 * pre:  A string to be inserted is passed in as parameter
 * post: The string is added to the Trie
 */
    void insert (const std::string& word);


    /* loadFromFile
 * Insert all words in the specified file into the Trie. Throws a
std::invalid_argument exception if the specified file cannot be
open
 * pre:  Receive the filename as parameter
 * post: All the words in the file is added to the Trie
 */
    void loadFromFile (const std::string& filename);

    /* isWord
 * This method returns true if str is in the Trie
else returns false
 *
 * pre:  A string is received as parameter
 * post:  Returns true if str is in the Trie
else returns false
 */
    bool isWord (const std::string& word) const;

    /* isPrefix
   * This method returns true if pre is a prefix of a word in the Trie
   *
   * pre:  A string is received as parameter
   * post:  returns true if pre is a prefix of a word in the sub-Trie starting at
  the given TrieNode, else returns false
   */
    bool isPrefix (const std::string& pre) const;

/* wordCount
return the number of words in the Trie
 *
 * pre: The Trie exist
 * post: return the number of words in the Trie
 */
    void print ( ) const;

    //Returns a count all the words in the Trie
    size_t wordCount ( ) const;
};


#endif //PROJECT9_TRIE_H

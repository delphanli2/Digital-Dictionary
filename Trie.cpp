// File name: Trie.cpp
// Author: Zexin Li
// Userid: liz27
// Email: zexin.li@vanderbilt.edu
// Class: session1
// Assignment Number: PA9
// Honor Statement: I do this without unauthorized aid
// Description: This file implements the Trie class which is a dictionary that holds different words
// Last Changed: 2018/04/18
#include "Trie.h"

//constructor
Trie::Trie(): myCount(0), rootNode(' ', false){
    //nothing to do
}

/* insert
 * This method Insert str into the Trie object. Create new TrieNodes
as needed and be sure to set the boolean flag on the last node to
true.
 *
 * pre:  A string to be inserted is passed in as parameter
 * post: The string is added to the Trie
 */
void Trie::insert (const std::string& word){
    if (isWord(word) || word.length() == 0){
        return;
    }
    else {
        rootNode.insert(word);
        myCount++;
    }
}


/* loadFromFile
 * Insert all words in the specified file into the Trie. Throws a
std::invalid_argument exception if the specified file cannot be
open
 * pre:  Receive the filename as parameter
 * post: All the words in the file is added to the Trie
 */
void Trie::loadFromFile (const std::string& filename){
    std::string str;
    std::ifstream file(filename.c_str());
    // Do error checking here
    if (!file) {
        std::invalid_argument("Error opening file");
    }
    else{
        while (file>>str){
            insert(str);
        }
    }
    file.close();
}

/* isWord
 * This method returns true if str is in the Trie
else returns false
 *
 * pre:  A string is received as parameter
 * post:  Returns true if str is in the Trie
else returns false
 */
bool Trie::isWord (const std::string& word) const{
    return rootNode.isWord(word);
}

/* isPrefix
 * This method returns true if pre is a prefix of a word in the Trie
 *
 * pre:  A string is received as parameter
 * post:  returns true if pre is a prefix of a word in the sub-Trie starting at
the given TrieNode, else returns false
 */
bool Trie::isPrefix (const std::string& pre) const{
    return rootNode.isPrefix(pre);
}


/* print
 Prints all words starting at the given TrieNode. The parameter
string str stores the letters of all previous TrieNode objects up to
the node currently being processed
 *
 * pre: The Trie exist
 * post: Print out all the words starting at the given TrieNode
 */
void Trie::print() const{
    rootNode.print("");
}

/* wordCount
return the number of words in the Trie
 *
 * pre: The Trie exist
 * post: return the number of words in the Trie
 */
size_t Trie::wordCount ( ) const{
    return myCount;
}

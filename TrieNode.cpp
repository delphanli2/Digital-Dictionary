// File name: TrieNode.cpp
// Author: Zexin Li
// Userid: liz27
// Email: zexin.li@vanderbilt.edu
// Class: session1
// Assignment Number: PA9
// Honor Statement: I do this without unauthorized aid
// Description: This is cpp file implements the TrieNode class
// Last Changed: 2018/04/18

#include <stdexcept>
#include "TrieNode.h"

//constructor
TrieNode::TrieNode(char c, bool b) : myLetter(c), endOfWord(b) {
    for (size_t i = 0; i < 26; i++) {
        children[i] = nullptr;
    }
}

//copy constructor
TrieNode::TrieNode(const TrieNode &rhs) : myLetter(rhs.myLetter), endOfWord(rhs.endOfWord) {
    for (size_t i = 0; i < 26; i++) {
        if (rhs.children[i] != nullptr) {
            children[i] = new TrieNode(rhs);
        } else {
            children[i] = nullptr;
        }
    }
}

//destructor
TrieNode::~TrieNode() {
    for (size_t i = 0; i < 26; i++) {
        delete children[i];
        children[i] = nullptr;
    }
}

//Assignment operator
const TrieNode &TrieNode::operator=(const TrieNode &rhs) {
    if (this != &rhs) {
        TrieNode temp(rhs);
        std::swap(myLetter, temp.myLetter);
        std::swap(endOfWord, temp.endOfWord);
        std::swap(children, temp.children);
    }
    return *this;
}

/* insert
 * This method Insert str starting with the given TrieNode. Create new TrieNodes
as needed and be sure to set the boolean flag on the last node to
true.
 *
 * pre:  A string to be inserted is passed in as parameter
 * post: The string is added starting with the given TrieNode
 */

void TrieNode::insert(const std::string &str) {
    if (str.length() == 0) {
        endOfWord = true;
    } else {
        int index = str[0] - 'a';
        if (children[index] == nullptr) {
            children[index] = new TrieNode(str[0], false);
            children[index]->insert(str.substr(1));
        } else {
            children[index]->insert(str.substr(1));
        }
    }
}

/* isWord
 * This method returns true if str is in the sub-Trie starting at the given TrieNode,
else returns false
 *
 * pre:  A string is received as parameter
 * post:  Returns true if str is in the sub-Trie starting at the given TrieNode,
else returns false
 */
bool TrieNode::isWord(const std::string &str) const {
    if (str.length() == 0) {
        return endOfWord;
    } else {
        int index = str[0] - 'a';
        if (children[index] != nullptr) {
            return children[index]->isWord(str.substr(1));
        }
    }
}

/* isPrefix
 * This method returns true if pre is a prefix of a word in the sub-Trie starting at
the given TrieNode, else returns false
 *
 * pre:  A string is received as parameter
 * post:  returns true if pre is a prefix of a word in the sub-Trie starting at
the given TrieNode, else returns false
 */
bool TrieNode::isPrefix(const std::string &pre) const {
    if (pre.length() == 0) {
        return true;
    } else if (isWord(pre)) {
        return true;
    } else {
        int index = pre[0] - 'a';
        if (children[index] != nullptr) {
            return children[index]->isPrefix(pre.substr(1));
        } else {
            return false;
        }
    }
}

/* print
 Prints all words starting at the given TrieNode. The parameter
string str stores the letters of all previous TrieNode objects up to
the node currently being processed
 *
 * pre:  The TrieNode exists
 * post: Print out all the words starting at the given TrieNode
 */
void TrieNode::print(const std::string &str) const {
    //Start from root node
    if (endOfWord) {
        std::cout << str << std::endl;
    }
    for (size_t i = 0; i < 26; i++) {
        if (children[i] != nullptr) {
            children[i]->print(str + children[i]->myLetter);
        }
    }
}

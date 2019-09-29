// File name: project9.cpp
// Author: Zexin Li
// Userid: liz27
// Email: zexin.li@vanderbilt.edu
// Class: session1
// Assignment Number: PA9
// Honor Statement: I do this without unauthorized aid
// Description: This file tests the Trie class
// Last Changed: 2018/04/18


#include "Trie.h"

int main() {
    Trie myTrie;
    myTrie.print();

    if (myTrie.wordCount() != 0){
        std::cout << "wordCount method doesn't work" << std::endl;
    }
    if (myTrie.isWord("applelelele")){
        std::cout << "isWord method doesn't work" << std::endl;
    }
    if (myTrie.isPrefix("tosss")){
        std::cout << "isPrefix method doesn't work" << std::endl;
    }
    myTrie.insert("for");
    myTrie.insert("fork");
    myTrie.insert("top");
    myTrie.insert("tops");
    myTrie.insert("topsy");
    myTrie.insert("toss");
    myTrie.insert("toss");
    myTrie.insert("");
    //Test the print method
    myTrie.print();

    //Test isWord method
    if (!myTrie.isWord("toss")){
        std::cout << "isWord method doesn't work" << std::endl;
    }
    if (myTrie.isWord("f")){
        std::cout << "isWord method doesn't work" << std::endl;
    }
    if (myTrie.isWord("")){
        std::cout << "isWord method doesn't work" << std::endl;
    }
    if (myTrie.isWord("applelelele")){
        std::cout << "isWord method doesn't work" << std::endl;
    }
    if (myTrie.isWord("")){
        std::cout << "isWord method doesn't work" << std::endl;
    }
    //Test load from files
    Trie load;
    load.loadFromFile("d1.txt");
    load.print();

    //Test isPrefix method
    if (!myTrie.isPrefix("top")){
        std::cout << "isPrefix method doesn't work" << std::endl;
    }
    if (myTrie.isPrefix("app")){
        std::cout << "isPrefix method doesn't work" << std::endl;
    }

    if (!myTrie.isPrefix("")){
        std::cout << "isPrefix method doesn't work" << std::endl;
    }
    if (myTrie.isPrefix("tosss")){
        std::cout << "isPrefix method doesn't work" << std::endl;
    }

    //Test count method
    if (myTrie.wordCount() != 6){
        std::cout << "wordCount method doesn't work" << std::endl;
    }




}


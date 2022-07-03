#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

#include "Dictionary.h"

using namespace std;

// predefining containers

typedef unordered_map<string, string> umap;
typedef vector<string> vect;

Dictionary::Dictionary(string fileName) {
    this->dictionary = makeDictionary(fileName);
    this->closed_form_words = closed_form();
}

umap Dictionary::getDictionary() {
    return this->dictionary;
}

umap Dictionary::makeDictionary(string fileName) {
    umap wordList;
    string word;
    // reading inputs from default file (dictionary.txt)
    ifstream inputFile;
    inputFile.open(fileName);

    while (inputFile >> word) {
        wordList.insert(make_pair(word, word));
    }

    inputFile.close();
    return wordList;
}

bool Dictionary::word_present(string word) {
    // find function searches the container for an element with k as key
    umap::iterator index = dictionary.find(word);
    if (index != dictionary.end()) return true;
    return false;
}

vect Dictionary::closed_form() {
    vect wordList;

    for (auto i = dictionary.begin(); i != dictionary.end(); i++) {
    
        string word = i->first;

        int length = word.length();
        string left, right;
        string exc = "IaA";
        for (int i = 0; i < length; i++) {
            left = word.substr(0, i);
            right = word.substr(i, length);
            if (word_present(left) && word_present(right)) {
                string line;
                
                // if (left.length() == 1 && exc.find(left) == string::npos || right.length() == 1 && exc.find(right) == string::npos)
                // continue;

                line = word + " - " + left + " + " + right;
                wordList.push_back(line);
            }
        }
    }
    /* since the dictionary is not lexicographically sorted,
    the vector 'wordList' contains words arranged in a random manner;
    it needs to be sorted*/
    sort(wordList.begin(), wordList.end());
    return wordList;
}

vect Dictionary::getClosedFormWords() {
    return this->closed_form_words;
}

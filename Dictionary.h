// Dictionary.h -- dictionary class interface 
// version - latest

#ifndef DICTIONARY01_H_
#define DICTIONARY_H_

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// predifining containers

typedef unordered_map<string, string> umap;
typedef vector<string> vect;

class Dictionary {

    umap dictionary;
    vect closed_form_words;

    public:
    Dictionary(string fileName); // contructor that makes an unordered map dictionary of the given filename
    umap makeDictionary(string fileName); // called int Dictionary constructor to make an unordered_map dictionary
    umap getDictionary(); // returns member dictionary
    vect closed_form(); // generates a vector comprising of all closed form compound words
    vect getClosedFormWords(); // returns member closed_form_words
    bool word_present(string word); // checks for the presence of a word in the dictionary
};

#endif


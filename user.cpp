#include <iostream>
#include <fstream>
#include <filesystem>

#include "Dictionary.h"

using namespace std;

typedef vector<string> vect;

void create_closed_form();

int main() {
    create_closed_form();
}

/* creates a file closed_form.txt 
and puts compound words in it */
void create_closed_form() {
    // Dictionary dict("dictionary.txt");
    Dictionary *dict = new Dictionary("dictionary.txt");
    ofstream outFile;
    outFile.open("closed_form.txt");
    // puts closed_form compound words in a file
    
    for (auto &word : dict->getClosedFormWords()) {
        outFile << word << endl;
    }

    outFile.close();
}

#include <iostream>
#include <fstream>
#include <filesystem>

#include "Dictionary.h"

using namespace std;

typedef vector<string> vect;

void create_closed_form();
void create_palindrome();

int main()
{
    create_closed_form();
    create_palindrome();
}

/* creates a file closed_form.txt
and puts compound words in it */
void create_closed_form()
{
    // Dictionary dict("dictionary.txt");
    Dictionary *dict = new Dictionary("dictionary.txt");
    ofstream outFile;
    outFile.open("closed_form.txt");
    // puts closed_form compound words in a file

    for (auto &word : dict->getClosedFormWords())
    {
        outFile << word << endl;
    }

    outFile.close();
}

void create_palindrome()
{
    // Dictionary dict("dictionary.txt");
    Dictionary *dict = new Dictionary("dictionary.txt");
    ofstream outFile;
    outFile.open("palindrome.txt");
    // puts closed_form compound words in a file

    for (auto &word : dict->getPalindromeWords())
    {
        outFile << word << endl;
    }

    outFile.close();
}

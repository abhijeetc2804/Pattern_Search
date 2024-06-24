// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include "Node.h"
using namespace std;

struct mySentence
{
    int book_code; int page; int paragraph; int sentence_no; string sentence;

    mySentence(int book_code1, int page1, int paragraph1, int sentence_no1, string sentence1){
        book_code = book_code1;
        page = page1;
        paragraph = paragraph1;
        sentence_no = sentence_no1;
        sentence = sentence1;
    }
};


class SearchEngine {
private:
    vector<mySentence> text;

public: 
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    SearchEngine();

    ~SearchEngine();
    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);
    Node* search(string pattern, int& n_matches);

    /* -----------------------------------------*/
};
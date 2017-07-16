// ==============================
// Javier Ramirez
// Created on September 3, 2016
// Assignment 1
// Course instructor: Boese
// ==============================



#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

// struct to store word + count combination
struct wordItem // structure for the words
{
    string word;
    int count;
};

void getStopWords(char *ignoreWordFileName, vector<string>& _vecIgnoreWords);
void printTopN(wordItem *&wordItemList, int topN);
bool isCommonWord(string word, vector<string>& _vecIgnore);
const int STOPWORD_LIST_SIZE = 50;

int main(int argc, char *argv[])
{
    int size = 100; //Initialize size
    wordItem *library = new wordItem[size]; //use later for doubling
    vector<string> vecIgnoreWords(STOPWORD_LIST_SIZE);

    int t = atoi(argv[1]); //This changes the command line argument to an integer
    getStopWords(argv[3], vecIgnoreWords);

    string element;
    int totalWords = 0; // total words in document
    int totalUniqueWords = 0; //total unique words
    int j = 0;
    int aindex = 0;
    int dbscnt = 0;
    ifstream mainfile(argv[2]);
    while(mainfile >> element)
    {
        totalWords = totalWords + 1;
        if(mainfile.is_open())
        {
            bool iscommon = isCommonWord(element, vecIgnoreWords);

             if(iscommon == false) // if the word is already in library the counter goes up
             {

                totalUniqueWords++;
                for(int i = 0; i <= aindex; i++)
                {
                    if(element ==library[i].word)
                    {
                        library[i].count++;
                        j = 1; // resets while loop
                    }
                }
                if(j == 0) // adds word if not in library
                {
                    library[aindex].word = element;
                    library[aindex].count = 1;
                    aindex++;
                }

                for(int k = 0; k<size; k++) // ensures the the library is in descending order
                {
                    if(library[k+1].count > library[k].count)
                    {
                        int temp = 0;
                        string term;
                        temp = library[k].count;
                        library[k].count = library[k+1].count;
                        library[k+1].count = temp;
                        term = library[k].word;
                        library[k].word = library[k+1].word;
                        library[k+1].word = term;

                    }
                }

                if(size <= aindex) // here we double
                {
                    dbscnt++;
                    wordItem *newArray = new wordItem[2*size];

                    for(int i = 0; i<size; i++)
                    {
                        newArray[i].count = library[i].count;
                        newArray[i].word = library[i].word;
                    }
                        size*=2;
                        delete[] library;
                        library = newArray;
                }

             }
        }
        j = 0;

    }

printTopN(library, t);
cout << "#" << endl;
cout << "Array double: " << dbscnt <<endl;
cout << "#" << endl;
cout << "Unique non-common words: " << aindex << endl;
cout << "#" << endl;
cout << "Total non-common words: " << totalUniqueWords << endl;

mainfile.close();
delete[] library;

}


/*
Function name: getStopWords
Purpose: read stop word list from file and store into vector
 @param ignoreWordFile - filename (the file storing ignore words)
 @param _vecIgnoreWords - store ignore from the file (pass by reference)
 @return - none
- Note: The number of words is fixed to 50
*/

void getStopWords(char *ignoreWordFileName, vector<string>& _vecIgnoreWords) // Neil nguyen and I worked on this part
{
    int i = 0;
    string iguword;
    cout << ignoreWordFileName << endl;
    ifstream myFile;
    myFile.open(ignoreWordFileName); // Opens the file
if(myFile == NULL) // if can't find file it prints failure to open
{
 cout<<"failure in opening file";
    exit(1);
}
else    //(myFile.is_open())
{
    //while(myFile >> iguword)
    while(getline(myFile,iguword)) // Reads the lines of HW1-stopwords.txt
    {
        //if(myFile.is_open())
        //{
            _vecIgnoreWords[i] = iguword;
            i++;
        //}
    }
        myFile.close(); //closes file after done being used
}
}
/*
Function name: isCommmonWord
Purpose: to see if a word is a common word
 @param word - a word (which you want to check if it is a common word)
 @param _vecIgnoreWords - the vector type of string storing ignore/common words
 @return - true (if word is a common word), or false (otherwise)
*/

bool isCommonWord(string word, vector<string>& _vecIgnoreWords)
{
    for(int i = 0; i < STOPWORD_LIST_SIZE; i++)
    {
         if(word == _vecIgnoreWords[i]) // if word is a common word it ignores it
        {
        return true; // ignores the word if common word
        }
    }
    return false; // if false checks for a different word if it is a common word
}
/*
Function name: printTopN
Purpose: to print the top N high frequency words
 @param wordItemList - a pointer that points to an array of wordItems
 @param topN - the number of top frequency words to print
 @return none
*/

void printTopN(wordItem *&wordItemList, int topN)
{
    for(int i = 0; i < topN; i++) // Counter
    {
        cout << wordItemList[i].count << " - " << wordItemList[i].word << endl; //prints out how many times the unique word came across and printed the word
    }
};

/*
Javier Ramirez
Elle Boese
October 7, 2016
*/

#include "MovieTree.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string line, word;
    string movie_name;
    int movie_rank, year, quantity;
    ifstream infile;
    infile.open(argv[1]);
    MovieTree MTree = MovieTree();

    while(getline(infile, line))
    {
        //if(line >> )
        stringstream ss(line);
        int counter = 0;
        while(getline(ss,word,','))
        {
            //switch case
            switch(counter)
            {
                case 0:
                {
                    movie_rank=stoi(word);
                    break;
                }
                case 1:
                {
                    movie_name = word;
                    break;
                }
                case 2:
                {
                    year = stoi(word);
                    break;
                }
                case 3:
                {
                    quantity = stoi(word);
                    break;
                }
            }

            counter++;
        }

        MTree.addMovieNode(movie_rank, movie_name, year, quantity);
    }
    string input;
    string name;
    while(input != "4"){
        cout << "======Main Menu======" << endl;

        cout << "1. Find a movie" << endl;

        cout << "2. Rent a movie" << endl;

        cout << "3. Print the inventory" << endl;

        cout << "4. Quit" << endl;

        getline (cin, input);
        if(input == "1"){
            cout << "Enter title:" << endl;
            getline (cin, name);
            MTree.findMovie(name);
        }

    else if(input == "2"){
        cout << "Enter title:" << endl;
        getline (cin, name);
        MTree.rentMovie(name);
    }
    else if(input == "3"){
        MTree.printMovieInventory();
    }
    else if(input == "4"){
        cout<< "Goodbye!" << endl;
    }
    }

    return 0;
}


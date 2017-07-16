/*
Javier Ramirez
Elle Boese
October 7, 2016
*/

#include <iostream>
#include "MovieTree.hpp"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


MovieTree::MovieTree()
{
    root = NULL;
}

MovieTree::~MovieTree()
{
    return;
}

void MovieTree::printMovieInventory(MovieNode *node)
{
    if(node != NULL)
    {
        printMovieInventory(node->leftChild);
        cout << "Rank: " << node-> ranking << " Title: " << node->title <<" Year: " << node->year << " Quantity: " << node->quantity << "\n" << endl;
        printMovieInventory(node->rightChild);
    }
}


void MovieTree::printMovieInventory()
{
    printMovieInventory(root);
}


void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity)
{
    MovieNode *adds= new MovieNode();
    MovieNode *ptr = new MovieNode;
    MovieNode *ptr_parent = new MovieNode;


    adds->ranking = ranking;
    adds->title = title;
    adds->year = releaseYear;
    adds->quantity = quantity;
    adds->leftChild = adds->rightChild = NULL;

    if(root == NULL){
        root = adds;
    }
    else{
        ptr = root;
        while(ptr != NULL){
            //less than go left
            ptr_parent=ptr;
            if(adds->title < ptr->title){
                ptr = ptr->leftChild;
            }
                // else going right
            else{
                ptr = ptr->rightChild;


            }
        }
        adds->parent=ptr_parent;
        if(adds->title < ptr_parent->title)
        {
            ptr_parent->leftChild = adds;

        }
        else{
            ptr_parent->rightChild = adds;
        }
    }
}

void MovieTree::findMovie(std::string title)
{
    MovieNode *foundMovie = root;

    while(foundMovie != NULL){
    if(root == NULL){
        cout<<"Empty"<<endl;
    }
    else{
        if(title.compare(foundMovie->title) < 0 ){
        foundMovie = foundMovie->leftChild;
        }

        else if(title.compare(foundMovie->title) > 0){
            foundMovie = foundMovie->rightChild;
        }
        else if(title.compare(foundMovie->title) == 0){
        //for rent move cout movie rented and decrement foundMovie->quantity
         cout << "Movie Info:" << endl;
         cout << "===========" << endl;
         cout << "Ranking:" << foundMovie->ranking << endl;
         cout << "Title:" << foundMovie->title << endl;
         cout << "Year:" << foundMovie->year << endl;
         cout << "Quantity:" << foundMovie->quantity << endl;
         break;
        }
        //addelse if where foundmovie->quantity is also (&&) == to 0
    }
    }
    if(foundMovie == NULL){
    cout <<"Movie not found." << endl;
    }

}
void MovieTree::rentMovie(std::string title)
{
     MovieNode *foundMovie = root;

    while(foundMovie != NULL){
    if(root == NULL){
        cout<<"Empty"<<endl;
    }
    else{
        if(title.compare(foundMovie->title) < 0 ){
        foundMovie = foundMovie->leftChild;
        }

        else if(title.compare(foundMovie->title) > 0){
            foundMovie = foundMovie->rightChild;
        }
        else if(title.compare(foundMovie->title) == 0){
        //for rent move cout movie rented and decrement foundMovie->quantity
        if(foundMovie->quantity > 0){
            foundMovie->quantity--;
        cout << "Movie has been rented." << endl;
         cout << "Movie Info:" << endl;
         cout << "===========" << endl;
         cout << "Ranking:" << foundMovie->ranking << endl;
         cout << "Title:" << foundMovie->title << endl;
         cout << "Year:" << foundMovie->year << endl;
         cout << "Quantity:" << foundMovie->quantity << endl;

         break;
        }
        else if(foundMovie->quantity == 0){
            cout << " Movie out of stock" << endl;
            break;
        }

        }
    }
    }
    if(foundMovie == NULL){
    cout <<"Movie not found." << endl;
    }
}

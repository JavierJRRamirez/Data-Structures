/*
 * Javier Ramirez
 * Elle Boese
 * 09/26/2016
 */

#include <iostream>
#include <stack>
#include "HW3-Todo-StackLinkedList.hpp"

using namespace std;

TodoStackLinkedList::TodoStackLinkedList()
{
    stackHead = NULL; // stackHead is initialized to Null
}

bool TodoStackLinkedList::isEmpty()
{
    if(stackHead == NULL) //if empty then return a Null
        return true;
    else{
        return false; //There something inside then there stack return false
    }

}

void TodoStackLinkedList::push(std:: string todoItem)
{

    TodoItem* stuff = new TodoItem;
    if(stackHead == NULL)
    {
        stackHead= stuff; // setting stackHead to stuff
        stackHead->todo=todoItem;
        stackHead->next=NULL;
       // cout <<"what"<<endl;
    }
    else{
        //stackHead->next = stuff; //if not NULL then sets stuff to the string
        stuff -> todo = todoItem;
        stuff -> todo = todoItem;
        stackHead -> next = stackHead;
        stackHead = stuff; // Sets whats stuff is to stackHead
        //cout << "hey" << endl;
    }

}

void TodoStackLinkedList::pop()
{
    if(stackHead == NULL)
        cout <<"Stack empty cannot pop an item"<<endl; // if Null prints to cout statement
    else{
        stackHead->next = stackHead;
cout << stackHead->todo << endl; //prints the last value
    }
}

TodoItem* TodoStackLinkedList::peek()
{
    if(stackHead == NULL){
    return NULL; // if no element it returns a null
    }

    else{
        return stackHead; // checks what the top element is
    }
}

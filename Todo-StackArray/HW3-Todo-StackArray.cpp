/*
 * Javier Ramirez
 * Elle Boese
 * 09/26/2016
 */
#include <vector>
#include <iostream>
#include <stack>
#include "HW3-Todo-StackArray.hpp"


using namespace std;

TodoStackArray::TodoStackArray()
{
    stackTop = -1; // initializes stackTop to -1

}

void TodoStackArray::push(std::string todoItem)
{
    if(stackTop == MAX_STACK_SIZE-1)
        cout << "Stack full, cannot add todo item." << endl; //if stack top has reached limit it print the cout statement
    else
    {
        stackTop++;
        stack[stackTop] = new TodoItem;
        stack[stackTop]->todo = todoItem; // adds one to stackTop if stackTop is not full
    }

}

bool TodoStackArray::isEmpty()
{
    if(stackTop == -1) // if empty your allowed to input elements
        return true;

        else
    {
        return false; // if false not empty
    }

}

bool TodoStackArray::isFull()
{
    if(stackTop == MAX_STACK_SIZE)
        return true; // if Full return true
    else
    {
        return false;// if false return false
    }
}

void TodoStackArray::pop()
{
    if(stackTop == -1)
        cout << "Stack empty, cannot pop an item." << endl; // of stack is empty you cant pop values out
    else{
        stack[stackTop] = NULL; // if has values inside you can take the last element out
        stackTop--;
    }
}

TodoItem* TodoStackArray::peek()
{
    if(stackTop == -1){
        cout << "Stack empty, cannot peek." << endl; // if no elements inside you can't see whats inside
        return NULL;
    }
    else{
        stack[stackTop]; return stack[stackTop]; //if there's something in the stack then check what's on the top
    }

}

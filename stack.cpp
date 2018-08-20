/*
/* Title: linkedlist.cpp
/* Author(s): Greyson Wang and Dayton Pukanich

/* Student Number:

/* Project: ENSC 251 Lab Assignment 2
*/

#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

Stack::Stack() : top(NULL)
{

}

Stack::~Stack()
{
    string temp;

    while (!empty())
    {
        temp = pop();
    }
}

void Stack::push(string& str)
{
    StackFramePtr temp;

    temp = new StackFrame;
    temp->next = top;
    temp->num_char = str.length();
    temp->str = new string;
    *(temp->str) = str;

    top = temp;
    return;
}

string Stack::pop()
{
    StackFramePtr destroy = top;
    string temp;

    if (top == NULL)
    {
        cout << "Empty list";
        return "";
    }

    temp = *(top->str);
    delete (top->str);

    top = top->next;
    delete destroy;

    return temp;
}

StackFramePtr Stack::remove_strings_length(int length)
{
    StackFramePtr before = top; //points to the node before the one being removed, in order to link it to the node after the one being removed
    StackFramePtr search = top; //pointer that goes through each node to search for string
    StackFramePtr newStack = NULL;
    StackFramePtr newStackTail = NULL;
    int searchPosition = 1;  //keeps track of which node search is currently on. First node is 1
    int beforePosition = 1;
    int timesFound = 0;

    if(empty() ) //empty stack
    {
      return NULL;
    }

  while (search != NULL)
    {


        if (search->num_char == length)
        {
            timesFound = timesFound + 1;

            //case 1: first node is the one being removed:

             if (searchPosition == 1)   //if the first node is the one beign removed, change top to point to new first node
            {
                top = top->next;

                if (newStack == NULL)
                {
                    newStack = before;
                    newStackTail = newStack;
                    newStack->next = NULL;

                }
                else
                {
                    //link the end of the new list with Search, and set the end marker of the new stack to the new last node
                    newStackTail->next = before;
                    newStackTail = newStackTail->next;
                    newStackTail->next = NULL;
                }

                before = top;
                search = top;
            }
            else    //case 2: node removed is not the first node
            {
            //move the pointer before to the node before the one being removed from the stack, so that this node can link to the node after the one being removed
               while ( beforePosition < (searchPosition - 1) )
               {
                   before = before->next;
                   beforePosition = beforePosition + 1;
               }
                search = search->next;     //Send search to next node so that the rest of the list is not lost

               //Add this node to the new list
               //case 1: new list is an empty list
                if (newStack == NULL)
                {
                    newStack = before->next;
                    newStackTail = newStack;
                    newStack->next = NULL;

                }
                else //case 2: new list already has nodes
                {
                    //link the end of the new list with Search, and set the end marker of the new stack to the new last node
                    newStackTail->next = before->next;
                    newStackTail = newStackTail->next;
                    newStackTail->next = NULL;  //sever the link to the old list
                }
                   before->next = search; //sever the link to the node being removed and link it to the rest of the list
            }


        }
        else
        {
            search = search->next;  //If search finds the value, it is sent to the next node already, so do this only if search doesn not find rhe value
            searchPosition = searchPosition + 1; //this is only done if a node isn't removed. If a node is removed, searchPosition is the same number
        }


    }

    if (timesFound == 0)
    {
        return NULL;
    }
    else
    {
        return newStack;
    }

}


bool Stack::empty()
{
    return(top==NULL);
}
ostream &operator<<(ostream &output, Stack &list)
{
    StackFramePtr iterate; //iterate through each item in the stack

    if (list.top != NULL)
    {
        for (iterate = list.top; iterate != NULL;  iterate = iterate->next)
            {
                cout << *(iterate->str) << " " << iterate->num_char << endl;
            }
    }
    else
    {
        cout << "empty list " << endl;
    }

    return output;
}

istream &operator>>(istream & input, Stack &list)
{
    string inputStr;
    input >> inputStr;

    list.push(inputStr);
    return input;
}

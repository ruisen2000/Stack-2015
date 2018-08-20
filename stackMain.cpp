
#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int main()
{
    string item1 = "banana";
    string item2 = "milk";
    string item3 = "apple";
    string item4 = "egg";
    string item5 = "soya";
    string item6 = "abcd";
    string pop1;
    string pop2;
    string topItem;
    Stack shoppingList;
    StackFramePtr fourLetter = NULL;
    StackFramePtr iter = NULL;

    cout << "adding abcd to list" << endl << endl;
    shoppingList.push(item6);

    cout << "adding banana to list" << endl << endl;
    shoppingList.push(item1);

    cout << "adding milk to list" << endl << endl;
    shoppingList.push(item2);

    cout << "adding apple to list" << endl << endl;
    shoppingList.push(item3);

    cout << "adding egg to list" << endl << endl;
    shoppingList.push(item4);

    cout << "adding soya to list" << endl << endl;
    shoppingList.push(item5);

    cout << "The first item in the list is: ";
    cout << shoppingList.pop() << endl << endl;

    cout << "The next item in the list is: ";
    cout << shoppingList.pop() << endl << endl;

    cout << "The next item in the list is: ";
    cout << shoppingList.pop() << endl << endl;

    cout << "The next item in the list is: ";
    cout << shoppingList.pop() << endl << endl;

    cout << "The next item in the list is: ";
    cout << shoppingList.pop() << endl << endl;

    cout << "The next item in the list is: ";
    cout << shoppingList.pop() << endl << endl;

    cout << "The next item in the list is: ";
    cout << shoppingList.pop() << endl << endl;

    cout << "The list contains: \n" << shoppingList << endl << endl;

   fourLetter = shoppingList.remove_strings_length(4);


    cout << "After removing 4 letter items, the list contains: \n" << shoppingList << endl << endl;

    cout << "The new list contains \n" << endl;
    for (iter = fourLetter; iter != NULL; iter = iter->next)
    {
        cout << *iter->str << endl;
    }
    return 0;
}

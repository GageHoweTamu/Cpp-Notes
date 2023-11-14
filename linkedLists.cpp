#include <iostream>
using namespace std;

/*

Using Linked Lists in C++

A Linked List is a data structure where each node contains a value and a pointer to the next node.

Linked Lists are useful because they are dynamic, meaning that they can change size during runtime.

Linked Lists are also useful because they are easy to insert and delete elements from.

Linked Lists are not useful for searching, because you have to start at the beginning and go through each node.
This is because nodes in a Linked List are not stored in contiguous memory locations, and can only be accessed through the last node.

*/

// creates custom datatype Node that contains a value and a pointer to the next "node"
class Node {
    public:
        int value;
        Node* next;
};

// prints all values in the linked list
void printList(Node* n) {
    while (n!=NULL) {               // while the node exists
        cout << n->value << endl;   // print its value, and...
        n = n->next;                // go to the next node
    }
}

// NOTE: Node* is not allowed as a name for a variable, so we refer to it as n (Node* n)

int main() {

    // create some nodes

    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // initialize them

    head->value = 1; // changes the value of the head node
    head->next = second; // changes head's "next" pointer to point to the second node
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = NULL; // sets the "next" pointer of the last node to NULL, since it is the last node

    printList(head);

    system("pause>0");
}
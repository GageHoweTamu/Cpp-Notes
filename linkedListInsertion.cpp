#include <iostream>
using namespace std;

/*

Insertion in Linked Lists in C++

We can insert nodes in a Linked List in several ways.

Insert at front: this will involve creating a new node, setting its value, and setting its "next" pointer to the current head node.
Then, we set the head node to the new node.

Insert at end: this will involve creating a new node, setting its value, and setting its "next" pointer to NULL, since it is the last node.
Then, we find the last node in the list, and set its "next" pointer to the new node.

Insert after a node n: we will need to pass the previous node as an argument, and then set the "next" pointer of the new node to the "next" pointer of the previous node.
Then, we set the "next" pointer of the previous node to the new node.
This will insert the new node after the previous node and make sure it points to the next node.

*/

class Node {
    public:
        int value;
        Node* next;
};

void printList(Node* n) {
    while (n!=NULL) {
        cout << n->value << endl;
        n = n->next;
    }
}

// insert a node at the front of the list
void insertAtFront(Node** head, int newvalue) {
    Node* newNode = new Node();                     // create a new node (object from the Node class)
    newNode->value = newvalue;                      // set its value to the input value
    newNode->next = *head;                          // set its "next" pointer to the current head
    *head = newNode;                                // make new node the head of the linked list
}

void insertAtEnd(Node** head, int newvalue) {
    Node* newNode = new Node();                     // create new node
    newNode->value = newvalue;                      // set its value
    newNode->next = NULL;                           // set its "next" pointer to NULL, since it is the last node
    
    if (*head == NULL) {                            // if the list is empty
        *head = newNode;                            // make the new node the head
        return;                                     // exit the function
    }

    else {
        Node* lastNode = *head;                     // create a pointer to the head node

        // this loop finds the last node in the list
        while (lastNode->next != NULL) {            // while the next node exists
            lastNode = lastNode->next;              // go to the next node
        }
        
        lastNode->next = newNode;                   // set the "next" pointer of the last node to the new node
    
    }
}

void insertAfter(Node* prevNode, int newvalue) {

    if (prevNode == NULL) {                              // check if previous node is null
        cout << "Previous node cannot be null" << endl;
        return;
    }

    Node* newNode = new Node();                         // prepare a new node
    newNode->value = newvalue;
    
    newNode->next = prevNode->next;                     // set the "next" pointer of the new node to the "next" pointer of the previous node
    prevNode->next = newNode;                           // set the "next" pointer of the previous node to the new node

}

int main() {

    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = NULL;


    insertAtFront(&head, 4); // pass the memory address of the head pointer, and the intended value of the new node
    insertAtFront(&head, 5);

    insertAtEnd(&head, 6);

    insertAfter(second, 7);

    printList(head);
}

// NOTE: the "second" node is now in the 4th position, because we inserted two nodes at the front of the list.
// Therefore, the node containing 7 is in the 5th position, not the 3rd.
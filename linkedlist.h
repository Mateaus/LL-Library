/*
 * File: linkedlist.h
 * -------------
 * This interface defines an abstraction for linkedlist.
 * Main purpose is to facilitate students on creating
 * nodes for a linked list in order to learn how to
 * properly manipulate a set of data in a linked list.
 */

#ifndef _linkedlist_h
#define _linkedlist_h

/*
 * Type: String
 * ------------
 * The type String is used in this interface to indicate
 * the usage of char*. There is no need to allocate memory,
 * if it's used while calling the function because they are
 * automatically allocated inside them.
 */

typedef char *String;

/*
 * Type: Node
 * -----------
 * The type Node is the concrete representation of the type
 * Node. In this implementation,the data is stored in a Node
 * which is then connected to a new Node when a new ID and Name
 * is inserted.
 */

typedef struct Node{
    int ID;
    String Name;
    struct Node *pNext;
} NodeT, *NodePtrT;

/*
 * Function: initializeLL
 * Usage: Node = initializeLL();
 * -----------------------------
 * This function initializes the Linked List to NULL.
 */

NodeT *initializeLL();

/*
 * Function: insertFileLL
 * Usage: insertFileLL(&Node, filename);
 * -------------------------------------
 * This functions inserts data to be stored
 * from a .txt file.
 * The format of the file.txt is:
 * - First column for ID
 * - Second column for Names
 * Example:
 * 5  Your Name
 * 3  Another Name
 */

void insertFileLL(NodeT **pHead, FILE *pFile);

/*
 * Function: insertLL
 * Usage: insertLL(&Node, ID, Name);
 * ---------------------------------
 * This function inserts a single data to be
 * stored manually.
 * If you wish to enter multiple nodes,
 * utilize a for loop where the amount of
 * iterations will be the size of the Linked List.
 */

void insertLL(NodeT **ppHead, int iID, String Name);

/*
 * Function: printLL
 * Usage: printLL(Node);
 * ---------------------
 * This function prints all the values
 * stored in the linked list.
 */

void printLL(NodeT *pHead);

/*
 * Function: freeLL
 * Usage: freeLL(Node);
 * --------------------
 * This function frees all the memory
 * allocated in the nodes throughout the
 * linked list.
 */

void freeLL(NodeT *pHead);

#endif

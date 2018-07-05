/*
 * File: linkedlist.c
 * ------------------
 * This file implements the linkedlist.h interface.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"


/* Private function prototypes */
static NodeT *allocateNode(int iID, String Name);
static NodeT *findPrevious(NodeT *pHead, int iID);

/* Exported entries */
void insertFileLL(NodeT **pHead, FILE *pFile)
{
    int iStudentID;
    char *iStudentName;
    if (pFile == NULL){printf("Error: Missing file\n");exit(0);}

    iStudentName = (char *)malloc(sizeof(char) * 100);
    if(iStudentName == NULL){printf("Error: Bad Memory Allocation");exit(0);}
    while(fscanf(pFile, "%d %[^\n]", &iStudentID, iStudentName) == 2)
    {
        // change memory allocation space to current string size;
        //iStudentName = (char *)realloc(iStudentName, strlen(iStudentName));
        // insert a LL to pHead
        insertLL(pHead, iStudentID, iStudentName);
    }

    free(iStudentName);
    return;
}

void insertLL(NodeT **ppHead, int iID, String Name)
{
    NodeT *pNew = NULL;
    NodeT *pPrevious = NULL;
    // malloc incoming data
    pNew = allocateNode(iID, Name);

    // find pPrevious to keep LL in order
    pPrevious = findPrevious(*ppHead, iID);

    if(pPrevious == NULL){
        pNew->pNext = (*ppHead);
        *ppHead = pNew;           //pHead on main is now pointing to pNew;
    } else {                      // meaning that it's copying everything pNew does!!
        pNew->pNext = pPrevious->pNext; // pHead->pNext = pPrevious->pNext;
        pPrevious->pNext = pNew;        // since pHead->pNext is pointing to pPrevious->pNext
    }                                   // now pHead->pNext is copying the new values of
                                        // pNew!
    return;
}

void printLL(NodeT *pHead)
{
    printf(" ----------------------------\n");
    while(pHead != NULL)
    {
        printf(" | ID:%d | Name:%-15s|\n", pHead->ID, pHead->Name);
        printf(" ----------------------------\n");
        pHead = pHead->pNext;
    }

    return;
}

void freeLL(NodeT *pHead)
{
    NodeT *p = NULL;

    while((p = pHead) != NULL)
    {
        pHead = pHead->pNext;
        free(p->Name);
        free(p);
    }

    return;
}

/* Private Functions */

/*
 * Function: allocateNode;
 * Usage: allocateNode(ID, Name);
 * ------------------------------
 * This function allocates memory for the Linked List
 * in order to be able to to store incoming data.
 */

NodeT *allocateNode(int iID, String Name)
{
    NodeT *pNew;
    // allocate memory for new data
    pNew = (NodeT *) malloc(sizeof(NodeT));
    if(pNew == NULL){
        printf("Error: Bad Memory allocation in pNew\n");
        exit(0);
    }
    pNew->Name = (char *) malloc(sizeof(char) * 100);
    if(pNew->Name == NULL){
        printf("Error: Bad Memory allocation in pNew->Name\n");
        exit(0);
    }
    // store values in LL
    pNew->ID = iID;
    strcpy(pNew->Name, Name);
    pNew->pNext = NULL;

    return pNew;
}

/*
 * Function: findPrevious;
 * Usage: findPrevious(*Node, &Node, ID);
 * ------------------------------
 * This function makes sure incoming data is
 * in the correct node from the low to high IDs.
 * While at the same time upadte ppPrevious LL.
 */

NodeT *findPrevious(NodeT *pHead, int iID)
{
    NodeT *pPrevious = NULL;

    while(pHead != NULL)
    {
        // if iID < pHead->ID, return pPrevious before it's updated.
        if(iID <= pHead->ID){
            return pPrevious;
        }
        // copy value of pHead before moving into the next values
        pPrevious = pHead;
        pHead = pHead->pNext;
    }

    return pPrevious;
}

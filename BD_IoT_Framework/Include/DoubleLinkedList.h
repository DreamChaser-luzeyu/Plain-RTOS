//
// Created by dream on 2023/2/17.
//

#ifndef KERNELLINKEDLIST_DOUBLELINKEDLIST_H
#define KERNELLINKEDLIST_DOUBLELINKEDLIST_H

#include "stdint-gcc.h"

typedef struct DoubleLinkedList_Node{
    struct DoubleLinkedList_Node* prev;
    struct DoubleLinkedList_Node* next;
} DoubleLinkedList_Node_Def;


void List_InitEmptyList_typeFunc(DoubleLinkedList_Node_Def* head);
void List_InsertToHead_typeFunc(DoubleLinkedList_Node_Def* node, DoubleLinkedList_Node_Def* head);
void List_InsertToTail_typeFunc(DoubleLinkedList_Node_Def* node, DoubleLinkedList_Node_Def* head);
void List_RemoveNode_typeFunc(DoubleLinkedList_Node_Def* node, DoubleLinkedList_Node_Def* head);

uint8_t List_IsEmpty_typeFunc(DoubleLinkedList_Node_Def* head);

#endif //KERNELLINKEDLIST_DOUBLELINKEDLIST_H

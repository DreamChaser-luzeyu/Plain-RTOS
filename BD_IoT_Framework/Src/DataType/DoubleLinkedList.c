//
// Created by dream on 2023/2/17.
//

#include <stdlib.h>
#include "DoubleLinkedList.h"

void List_InitEmptyList_typeFunc(DoubleLinkedList_Node_Def* head) {
    if(head != NULL) {
        head->next = head;
        head->prev = head;
    }
}

void List_InsertToHead_typeFunc(DoubleLinkedList_Node_Def* node, DoubleLinkedList_Node_Def* head) {
    if(head != NULL && node != NULL) {
        DoubleLinkedList_Node_Def* oldFirstNode = head->next;
        // 共有：链表头、要插入的节点、原来的第一个节点 三个节点需要处理
        // 修改链表头节点
        head->next = node;
        // 修改要插入的节点
        node->next = oldFirstNode;
        node->prev = head;
        // 修改原来的第一个节点
        oldFirstNode->prev = node;
    }
}

void List_InsertToTail_typeFunc(DoubleLinkedList_Node_Def* node, DoubleLinkedList_Node_Def* head) {
    if(head != NULL && node != NULL) {
        DoubleLinkedList_Node_Def* oldLastNode = head->prev;
        head->prev = node;
        node->next = head;
        node->prev = oldLastNode;
        oldLastNode->next = node;
    }
}

void List_RemoveNode_typeFunc(DoubleLinkedList_Node_Def* node, DoubleLinkedList_Node_Def* head) {
    if(head != NULL && node != NULL) {
        DoubleLinkedList_Node_Def* nodeBeforeNode = node->prev;
        DoubleLinkedList_Node_Def* nodeAfterNode = node->next;
        nodeBeforeNode->next = nodeAfterNode;
        nodeAfterNode->prev = nodeBeforeNode;
//        free(node);
    }
}

uint8_t List_IsEmpty_typeFunc(DoubleLinkedList_Node_Def* head) {
    if(head != NULL && head->next != NULL && head->prev != NULL) {
        if(head->next == head && head->prev == head) {
            return 1;   // Empty
        }
        else {
            return 0;   // Not empty
        }
    }
    return 2;           // Error
}
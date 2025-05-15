#ifndef _CP_10_T_
#define _CP_10_T_
#include <iostream>
#include "export_macro.h"


// ******************************************************************
// *                                                                *
// *                   single linkded list                          *
// *               - whose head stores nothing                      *
// *               - elements counting start from 0                 *
// *                                                                *
// ******************************************************************
template <typename T>
struct LNodeT
{
    T data;
    LNodeT* next;
    // LNode* prior;
};

///// @brief find the NO.idx Node
///// @param head -I head of the link list 
///// @param idx -I  index of the node
///// @return the pointer to the node 
//template <typename T>
//I2A_API LNodeT<T>* getNodeT(LNodeT<T>* head, int idx);
//
///// @brief length of link list
///// @param head 
//
///// @retu
//template <typename T>
//I2A_API int lengthLinkListT(LNodeT<T>* head);
//
//template <typename T>
//I2A_API void insertLinkListT(LNodeT<T>** head, int idx, T value);
//
///// @brief empty the link list
///// @param head 
//template <typename T>
//I2A_API void emptyLNodeT(LNodeT<T>** head);
//
///// @brief delete the link list
///// @param head 
//template <typename T>
//I2A_API void deleteLNodeT(LNodeT<T>** head, int idx);


//#include "../src/chapter10_temp.cpp"


template <typename T>
LNodeT<T>* createNodeT(T value) {
    LNodeT<T>* node = new LNodeT<T>;
    node->data = value;
    node->next = nullptr;
    return node;
}


/// @brief find the NO.idx Node
/// @param head -I head of the link list 
/// @param idx -I  index of the node
/// @return the pointer to the node 
template <typename T>
LNodeT<T>* getNodeT(LNodeT<T>* head, int idx)
{
    if (head == nullptr)
        return head;
    LNodeT<T>* p = head;
    int loc = 0;
    while (p->next != nullptr && idx != 0)
    {
        p = p->next;
        loc++;
        idx--;
    }
    if (idx > 0 || idx < -1)
    {
        abortMesage("Error: idx is out of range of the LNode");
        abort();
    }
    return p;
}

/// @brief length of link list
/// @param head 
/// @return 
template <typename T>
int lengthLinkListT(LNodeT<T>* head)
{
    LNodeT<T>* p = head;
    int i = 0;
    while (p != NULL) {
        p = p->next;
        i++;
    }
    return i;
}

template <typename T>
void insertLinkListT(LNodeT<T>** head, int idx, T value)
{
    LNodeT<T>* p;
    LNodeT<T>* tmp = createNodeT(value);
    p = getNodeT(*head, idx - 1);

    //tmp = new LNodeT<T>;
    if (p == nullptr) {
        *head = tmp;
    }
    else if (tmp) {
        tmp->next = p->next;
        p->next = tmp;
    }
}


/// @brief empty the link list
/// @param head 
template <typename T>
void emptyLNodeT(LNodeT<T>** head)
{
    LNodeT<T>* p;
    while (*head)
    {
        p = (*head)->next;
        free(*head);
        *head = p;
    }
    //head->next = NULL;
}

/// @brief delete the link list
/// @param head 
template <typename T>
void deleteLNodeT(LNodeT<T>** head, int idx)
{
    LNodeT<T>* p = *head;
    LNodeT<T>* pre = nullptr;
    while (p) {
        if (idx) {
            pre = p;
            p = p->next;
            idx--;
        }
        else if (pre) {
            pre->next = p->next;
            free(p);
            p = nullptr;
        }
        else {
            *head = p->next;
            free(p);
            p = nullptr;
        }
    }
}








I2A_API void callLNodeTemp()
{
    printf(">> Calling the link list template\n");
    int size = 5;
    LNodeT<float>* head = nullptr;
    //CreateLinkListT(&head);
    for (int i = 0; i < size; i++)
        insertLinkListT(&head, i, (float)i); // insert in the front

    int cnt = 0;
    LNodeT<float>* p = head;
    while (p != NULL)
    {
        printf("No.%d element is %f\n", cnt++, p->data);
        p = p->next;
    }
    int len = lengthLinkListT(head);
    printf("the length of the list is %d\n", len);

    for (int i = 0; i < size; i++) {
        deleteLNodeT(&head, 0);
        len = lengthLinkListT(head);
        printf("the length of empty list is %d after delete\n", len);
    }
    emptyLNodeT(&head);
    len = lengthLinkListT(head);
    printf("the length of empty list is %d\n", len);
    std::cout << head << std::endl;
}


#endif

//#ifndef _CHAPTER10_TEMP_CPP_
//#define _CHAPTER10_TEMP_CPP_
//
//
//#include "chapter10_temp.h"
//#include "common.h"
//#include <vector>
//
//
//// ******************************************************************
//// *                                                                *
//// *                   single linkded list                          *
//// *               - whose head stores nothing                      *
//// *               - elements counting start from 0                 *
//// *                                                                *
//// ******************************************************************
//
//
//template <typename T>
//LNodeT<T>* createNodeT(T value) {
//    LNodeT<T> *node = new LNodeT<T>;
//    node->data = value;
//    node->next = nullptr;
//    return node;
//}
//
//
///// @brief find the NO.idx Node
///// @param head -I head of the link list 
///// @param idx -I  index of the node
///// @return the pointer to the node 
//template <typename T>
//LNodeT<T>* getNodeT(LNodeT<T>* head, int idx)
//{
//    if (head == nullptr)
//        return head;
//    LNodeT<T>* p = head;
//    int loc = 0;
//    while (p->next != nullptr && idx != 0)
//    {
//        p = p->next;
//        loc++;
//        idx--;
//    }
//    if (idx > 0 || idx < -1)
//    {
//        abortMesage("Error: idx is out of range of the LNode");
//        abort();
//    }
//    return p;
//}
//
///// @brief length of link list
///// @param head 
///// @return 
//template <typename T>
//int lengthLinkListT(LNodeT<T>* head)
//{
//    LNodeT<T>* p = head;
//    int i = 0;
//    while (p != NULL) {
//        p = p->next;
//        i++;
//    }
//    return i;
//}
//
//template <typename T>
//void insertLinkListT(LNodeT<T>** head, int idx, T value)
//{
//    LNodeT<T>* p;
//    LNodeT<T>* tmp = createNodeT(value);
//    p = getNodeT(*head, idx - 1);
//
//    //tmp = new LNodeT<T>;
//    if (p == nullptr) {
//        *head = tmp;
//    }
//    else if (tmp){
//        tmp->next = p->next;
//        p->next = tmp;
//    }
//}
//
//
///// @brief empty the link list
///// @param head 
//template <typename T>
//void emptyLNodeT(LNodeT<T>** head)
//{
//    LNodeT<T>* p;
//    while (*head)
//    {
//        p = (*head)->next;
//        free(*head);
//        *head = p;
//    }
//    //head->next = NULL;
//}
//
///// @brief delete the link list
///// @param head 
//template <typename T>
//void deleteLNodeT(LNodeT<T>** head, int idx)
//{
//    LNodeT<T>* p = *head;
//    LNodeT<T>* pre = nullptr;
//    while (p) {
//        if (idx) {
//            pre = p;
//            p = p->next;
//            idx--;
//        }
//        else if (pre){
//            pre->next = p->next;
//            free(p);
//            p = nullptr;
//        }
//        else {
//            *head = p->next;
//            free(p);
//            p = nullptr;
//        }
//    }
//}
//
//#endif

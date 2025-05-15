#ifndef _CP22_CPP_
#define _CP22_CPP_

#include "chapter22.h"


// ******************************************************************
// *                                                                *
// *                   Breadth-first search                         *
// *               - whose head stores nothing                      *
// *               - elements counting start from 0                 *
// *                                                                *
// ******************************************************************



/**
*   graph demonstration
* 
*   0-----1
*   |    /|\
*   |   / | \
*   |  /  |  2
*   | /   | /
*   |/    |/
*   4-----3
*  start from 0, then 
*  distance0: 0; 
*  distance1: 1,4; 
*  distance2: 2,3
*/ 
//template <typename T>
//extern LNodeT<LNodeT<T>*>* initGraphAdj()
//{
//	T adj_list[5][4] = { {1,4}, {0,4,2,3}, {2,4}, {1,4,2}, {3,0,1} };
//	int adj_len[5] = { 2, 4, 2, 3, 3 };
//	LNodeT<LNodeT<T>*>* head = nullptr;
//
//	for (int j = 0; j < 5; j++) {
//		int size = 5;
//		LNodeT<T>* adj_mem = nullptr;
//		for (int i = 0; i < adj_len[j]; i++) {
//			insertLinkListT(&adj_mem, i, adj_list[j][i]); // insert in the front
//		}
//		insertLinkListT(&head, j, adj_mem);
//	}
//	return head;
//}

#endif

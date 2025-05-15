#ifndef _CHAPTER_22_
#define _CHAPTER_22_

#include <iostream>
#include "common.h"
#include "chapter10_temp.h"
//#include "../src/chapter22.cpp"
#include "queue"
#include <typeinfo>
/// <summary>
/// color, distance, parent
/// </summary>
struct Graph_Vertex
{
	std::string name;
	int color; // 0: white, 1: gray, 2: black
	int distance;
	LNodeT<Graph_Vertex>* parent;
};


template <typename T>
struct Graph
{
	LNodeT<Graph_Vertex>* vertex; // the pointer to the head of the vertex list	
	LNodeT<LNodeT<T>*>* adj_list; // the pointer to the head of the adjacency list
};


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
template <typename T>
extern LNodeT<LNodeT<T>*>* initGraphAdj()
{
	T adj_list[5][4] = { {1,4}, {0,4,2,3}, {2,4}, {1,4,2}, {3,0,1} };
	int adj_len[5] = { 2, 4, 2, 3, 3 };
	LNodeT<LNodeT<T>*>* head = nullptr;

	for (int j = 0; j < 5; j++) {
		int size = 5;
		LNodeT<T>* adj_mem = nullptr;
		for (int i = 0; i < adj_len[j]; i++) {
			insertLinkListT(&adj_mem, i, adj_list[j][i]); // insert in the front
		}
		insertLinkListT(&head, j, adj_mem);
	}
	return head;
}


template <typename T>
extern void BFS(Graph<T>* g1, int start_vertex_id)
{
	// init white
	Graph<T> g = *g1;
	for (int i = 0; i < lengthLinkListT(g.adj_list); i++) {
		//Graph_Vertex g_v = { name[i], 0, max_int, nullptr};
		LNodeT<Graph_Vertex>* tmpv = getNodeT(g.vertex, i);
		tmpv->data.color = 0;
		tmpv->data.distance = 0;
		tmpv->data.parent = nullptr;
	}
	LNodeT<Graph_Vertex>* start_vertex = getNodeT(g.vertex, start_vertex_id);
	start_vertex->data.color = 1;
	start_vertex->data.distance = 0;
	std::queue<int> que_vertex_id;
	que_vertex_id.push(start_vertex_id);
	while (!que_vertex_id.empty()) {
		int u_id = que_vertex_id.front(); //dequeue
		que_vertex_id.pop();
		LNodeT<LNodeT<T>*>* adj_u = getNodeT(g.adj_list, u_id);
		LNodeT<Graph_Vertex>* u = getNodeT(g.vertex, u_id);
		std::cout << "> distance: " << u->data.distance  + 1 << std::endl;
		for (int i = 0; i < lengthLinkListT(adj_u->data); i++) {
			int v_id = getNodeT(adj_u->data, i)->data;
			LNodeT<Graph_Vertex>* v = getNodeT(g.vertex, v_id);
			if (v->data.color == 0) {
				v->data.color = 1;
				v->data.distance = u->data.distance + 1;
				v->data.parent = u;
				que_vertex_id.push(v_id);
				std::cout << " " << v_id;
			}
		}
		printf("\n");
		u->data.color = 2;
	}
}

template <typename T>
void  printPath(Graph<T>* g, LNodeT<Graph_Vertex>* start, LNodeT<Graph_Vertex>* v)
{
	//LNodeT<Graph_Vertex>* v = getNodeT(g->vertex, dst_id);
	if (start == v) {
		std::cout << "  - start vertex: " << v->data.name << std::endl;
	}
	else if (v->data.parent == nullptr) {
		std::cout << "  E: no path from the start vertex " << start->data.name << " to vertex" << v->data.name << std::endl;
	}
	else 
	{
		printPath(g, start, v->data.parent);
		std::cout << "  - bypass vertex: " << v->data.name << std::endl;
	}
}

void callBFS()
{
    printf(">> Calling BFS\n");
	Graph<int> g = {nullptr, nullptr};
	std::string name[5] = {"0", "1", "2", "3", "4"};
	g.adj_list = initGraphAdj<int>();
	for (int i = 0; i < lengthLinkListT(g.adj_list); i++) {
		Graph_Vertex g_v = {name[i], 0, max_int, nullptr};
		insertLinkListT(&g.vertex, i, g_v);
	}
	BFS<int>(&g, 0);
	LNodeT<Graph_Vertex>* v = getNodeT(g.vertex, 2);

	std::cout << "> bfs tree: " << std::endl;
	printPath(&g, g.vertex, v);

	std::cout << "finish\n" << std::endl;
}

#endif
#ifndef _CHAPTER_22_
#define _CHAPTER_22_

#include <iostream>
#include "chapter10_temp.h"
#include "../src/chapter22.cpp"
#include "queue"
/// <summary>
/// color, distance, parent
/// </summary>
struct Graph_Vertex
{
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

template <typename T>
extern void BFS(Graph<T>* g1, int start_vertex_id)
{
	Graph<T> g = *g1;
	for (int i = 0; i < lengthLinkListT(g.adj_list); i++) {
		Graph_Vertex g_v = { 0, max_int, nullptr };
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


void callBFS()
{
    printf(">> Calling BFS\n");
	Graph<int> g = {nullptr, nullptr};
	g.adj_list = initGraphAdj<int>();
	for (int i = 0; i < lengthLinkListT(g.adj_list); i++) {
		Graph_Vertex g_v = { 0, max_int, nullptr };
		insertLinkListT(&g.vertex, i, g_v);
	}
	BFS<int>(&g, 0);
	std::cout << "finish\n" << std::endl;
}

#endif
// Graph.cpp: implementation of the Graph class.
//
//////////////////////////////////////////////////////////////////////

#include "Graph.h"
#define INFINITY 1000000
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Graph::Graph() {            // Constructor
	numEdge = 0;	
}

Graph::~Graph() {           // Destructor: return allocated space
	// Remove all of the edges
	for (int v=0; v<list.size(); v++) { // For each vertex...
		Edge p = list[ v ].first;
		while (p != NULL) { // return its edges
			Edge temp = p;
			p = p->next;
			delete temp;
		}
	}	
	
}

int Graph::n() { return list.size(); } // Number of vertices

int Graph::e() { return numEdge; }   // Number of edges

Edge Graph::first(int v)    // Get the first edge for a vertex
{ return list[ v ].first; }

bool Graph::isEdge(Edge w)  // TRUE if this is an edge
{ return w != NULL; }

Edge Graph::next(Edge w) {  // Get next edge for a vertex
	if (w == NULL) return NULL;
	else return w->next;
}

int Graph::v1(Edge w) { return w->v1; } // Vertex edge comes from

int Graph::v2(Edge w) { return w->v2; } // Vertex edge goes to

weightType Graph::weight(int i, int j) { // Return weight of edge
	for (Edge curr = list[ i ].first; curr != NULL; curr = curr->next)
		if (curr->v2 == j) return curr->weight;
		return INFINITY;
}

weightType Graph::weight(Edge w) // Return weight of edge
{ if (w == NULL) return INFINITY; else return w->weight; }

bool Graph::getMark(int v) { return Mark[ v ]; }

void Graph::setMark(int v, bool val) { Mark[ v ] = val; }



//----------插入或删除数据-----------------------------
void Graph::InsertVertex ( const Type & vertexData ){
	list.push_back( VertexNode(vertexData,NULL) );
	Mark.push_back(false);
}
void Graph::InsertEdge ( const int v1, const int v2, weightType weight ){
	Edge edge= new EdgeNode(v1,v2,weight);
	edge->next = list[ v1 ].first;
	list[ v1 ].first = edge;
	numEdge++;
}
void Graph::RemoveVertex ( const int v ){
}
void Graph::RemoveEdge ( const int v1, const int v2 ){
}


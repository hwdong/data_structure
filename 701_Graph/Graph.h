// Graph.h: interface for the Graph class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPH_H__C891E2F0_794B_4ADD_8772_55BA367C823E__INCLUDED_)
#define AFX_GRAPH_H__C891E2F0_794B_4ADD_8772_55BA367C823E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <cassert>
#include <vector>
using namespace std;

#define NULL 0
typedef int weightType;
typedef char Type; //数据元素类型

class EdgeNode {               // A singly-linked list node
public:
  weightType weight;                  // Edge weight
  int v1;                      // Vertex edge comes from
  int v2;                      // Vertex edge goes to
  EdgeNode* next;              // Pointer to next edge in list
  EdgeNode(int vt1, int vt2, weightType w, EdgeNode* nxt =NULL)
    { v1 = vt1; v2 = vt2; weight = w; next = nxt; } // Constructor
  EdgeNode(EdgeNode* nxt =NULL) { next = nxt; }     // Constructor
};

typedef EdgeNode* Edge;

struct VertexNode{
	Type data;
	Edge first;
	VertexNode(Type d,Edge e):data(d),first(e){}
};
typedef VertexNode Vertex;

class Graph {                  // Graph class: Adjacency list
private:
  vector<Vertex> list;         //The vertex list
  int numEdge;                 // Number of edges
  vector<bool> Mark;           // The mark array
public:
  Graph();                     // Constructor
  ~Graph();                    // Destructor
  int n();                     // Number of vertices for graph
  int e();                     // Number of edges for graph  
  Edge first(int);             // Get the first edge for a vertex
  bool isEdge(Edge);           // TRUE if this is an edge
  Edge next(Edge);             // Get next edge for a vertex
  int v1(Edge);                // Return vertex edge comes from
  int v2(Edge);                // Return vertex edge goes to
  weightType weight(int, int);        // Return weight of edge
  weightType weight(Edge);            // Return weight of edge
  bool getMark(int);           // Return a Mark value
  void setMark(int, bool);     // Set a Mark value

  void setVertex(int i,Type vertexData){ 
	  assert(i>=0&&i<list.size()) ; list[ i ].data =vertexData; }
  Type getVertex(int i){ 
	  assert(i>=0&&i<list.size()) ; return list[ i ].data; }
  void InsertVertex ( const Type & vertexData );
  void InsertEdge ( const int v1, const int v2, weightType weight );
  void RemoveVertex ( const int v );
  void RemoveEdge ( const int v1, const int v2 );
  //....
};

void Dijkstra_shortest_Path(Graph& G, int s,weightType D[ ],int P[ ]);


#endif // !defined(AFX_GRAPH_H__C891E2F0_794B_4ADD_8772_55BA367C823E__INCLUDED_)

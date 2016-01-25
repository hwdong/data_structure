#include "Graph.h"

#define INFINITY 1000000
const bool VISITED = true;
const bool UNVISITED = false;
int minVertex(Graph& G, int* D);  //在距离数组D中找最小的未加入S中的最短距离



void Dijkstra_shortest_Path(Graph& G, int s,weightType D[ ],int P[ ]) {  // Compute shortest path distances
	// int D[ G.n() ];

	int i;
	for(i = 0 ;i< G.n(); i++)  G.setMark(s, UNVISITED);

	//将s作为起点，初始化距离数组和路径数组
	for ( i=0; i<G.n(); i++){     // Initialize
		D[ i ] = INFINITY; P[ i ] = s;
	}
	D[ s ] = 0; G.setMark(s, VISITED);      //add s to S
	for (Edge e = G.first(s); G.isEdge(e); e = G.next(e))
		D[ G.v2(e) ] =  G.weight(e);

	//在未加入S中的顶点中选择最短路径的那个顶点，加入S,并更新距离和路径数组
	int vn = G.n();
	for (i=0; i<vn-1; i++) {          // Process the vertices
		int v = minVertex(G, D);       //在不在S中的顶点中查找D(v)最小的顶点v
		if (D[ v ] == INFINITY) return;  // 没有可以到达的顶点了
		G.setMark(v, VISITED);
		for (Edge e = G.first(v); G.isEdge(e); e = G.next(e))  //更新v的所有邻接点v2的D(v2)和P(v2)
			if (D[ G.v2(e) ] > (D[v] + G.weight(e))){
				D[ G.v2(e) ] = D[v] + G.weight(e);
				P[ G.v2(e) ]  = v;   //
			}
	}

	for(i = 0 ;i< G.n(); i++)  G.setMark(s, UNVISITED);
}

int minVertex(Graph& G, int* D) { // Find min cost vertex
	int v;  // Initialize v to any unvisited vertex;
	for (int i=0; i<G.n(); i++)
		if (G.getMark(i) == UNVISITED) { v = i; break; }
	for (i++; i<G.n(); i++)  // Now find smallest D value
		if ((G.getMark(i) == UNVISITED) && (D[ i ] < D[ v ])) 
			v = i;
	return v;
}


/*================最短路径问题：Dijkstra算法=================
-----------数据结构----------------
D = Distance：起点到终点的当前距离
P = Path：终点的前一个顶点
S = Set：已知最短路径的目的顶点集合

-----------算法过程----------------
1) 初始化
   S = {V0}
   对于所有顶点v
     若存在弧<V0,V>，D(v) = arcs(V0,V)
     否则 D(v) = ∞
2) 循环(直到找不到从v0可以达到的顶点){
      在不在S中的顶点中查找D(w)最小的顶点w
      把w加入S，即w已知最短路径
      更新w的所有邻接点v的D(v)和P(v)
	  if( D(w)+c(w,v) < D(v) ){
	      D(v) = D(w)+arcs(w,v);
          P(v) = w;
      }
 }
 */

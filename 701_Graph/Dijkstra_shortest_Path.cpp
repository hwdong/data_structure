#include "Graph.h"

#define INFINITY 1000000
const bool VISITED = true;
const bool UNVISITED = false;
int minVertex(Graph& G, int* D);  //�ھ�������D������С��δ����S�е���̾���



void Dijkstra_shortest_Path(Graph& G, int s,weightType D[ ],int P[ ]) {  // Compute shortest path distances
	// int D[ G.n() ];

	int i;
	for(i = 0 ;i< G.n(); i++)  G.setMark(s, UNVISITED);

	//��s��Ϊ��㣬��ʼ�����������·������
	for ( i=0; i<G.n(); i++){     // Initialize
		D[ i ] = INFINITY; P[ i ] = s;
	}
	D[ s ] = 0; G.setMark(s, VISITED);      //add s to S
	for (Edge e = G.first(s); G.isEdge(e); e = G.next(e))
		D[ G.v2(e) ] =  G.weight(e);

	//��δ����S�еĶ�����ѡ�����·�����Ǹ����㣬����S,�����¾����·������
	int vn = G.n();
	for (i=0; i<vn-1; i++) {          // Process the vertices
		int v = minVertex(G, D);       //�ڲ���S�еĶ����в���D(v)��С�Ķ���v
		if (D[ v ] == INFINITY) return;  // û�п��Ե���Ķ�����
		G.setMark(v, VISITED);
		for (Edge e = G.first(v); G.isEdge(e); e = G.next(e))  //����v�������ڽӵ�v2��D(v2)��P(v2)
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


/*================���·�����⣺Dijkstra�㷨=================
-----------���ݽṹ----------------
D = Distance����㵽�յ�ĵ�ǰ����
P = Path���յ��ǰһ������
S = Set����֪���·����Ŀ�Ķ��㼯��

-----------�㷨����----------------
1) ��ʼ��
   S = {V0}
   �������ж���v
     �����ڻ�<V0,V>��D(v) = arcs(V0,V)
     ���� D(v) = ��
2) ѭ��(ֱ���Ҳ�����v0���Դﵽ�Ķ���){
      �ڲ���S�еĶ����в���D(w)��С�Ķ���w
      ��w����S����w��֪���·��
      ����w�������ڽӵ�v��D(v)��P(v)
	  if( D(w)+c(w,v) < D(v) ){
	      D(v) = D(w)+arcs(w,v);
          P(v) = w;
      }
 }
 */

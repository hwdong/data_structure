#include <iostream>
#include <stack>
#include "Graph.h"
void main(){
	Graph G;
	Type vdata;
	cout<<"请依次输入顶点数据，用'ctrl+Z' 'ctrl+Z'结束输入\n";
	while(cin>>vdata){
		G.InsertVertex(vdata);
	}
	cin.clear();  //置为正常状态

	int v1 ,v2;
	weightType weight;
	cout<<"请输入边信息(格式为 v1 v2 weight):";
	
	cin>>v1>>v2>>weight;
	while(v1>=0&&v2>=0){
		G.InsertEdge(v1,v2,weight);
		cout<<"请输入边信息(格式为 v1 v2 weight):";
		cin>>v1>>v2>>weight;
	}


	int i;
	cout<<"图中顶点数据为:";
	for( i = 0 ;i <G.n(); i++)
		cout<<G.getVertex(i)<<" ";
	cout<<endl;

	cout<<"图中边数据为:";
	for( i = 0 ;i <G.n(); i++){
		Edge edge = G.first(i);
		while(edge){
			cout<<"("<<edge->v1<<" "<<edge->v2<<" "<<edge->weight<<") ";
			edge = G.next(edge);
		}
	}
	cout<<endl;


	//Dijkstra_shortest_Path算法
	weightType *D = new weightType[ G.n() ]; 
	int *P = new int[ G.n() ];
	int s;    
	cout<<"请输入起点的下标:";   cin>>s;
	Type sdata = G.getVertex(s);
	Dijkstra_shortest_Path(G,s,D,P);

	cout<<"输出所有最短路径,格式（终点，最短路径长度，最短路径）\n";
	stack<int> pathStack;
	Type vertexdata;
	for( i = 0; i<G.n(); i++){
		if(i==s) continue;		
		vertexdata = G.getVertex(i);
		if(D[ i ]>=100000){
			cout <<"从起点"<<sdata<<"到顶点"<<vertexdata<<"没有路径\n"; 
			continue;
		}
		for(int j = P[ i ];j!=s;j = P[ j ])
			pathStack.push(j);

		cout<<vertexdata<<" "<<D[ i ]<<" "<<sdata;

		while(!pathStack.empty()){
			int j = pathStack.top(); pathStack.pop();			
			cout<<G.getVertex(j);  
		}
		cout<<G.getVertex(i)<<"\n";
	}

	delete[ ] D; delete[ ] P; 

}




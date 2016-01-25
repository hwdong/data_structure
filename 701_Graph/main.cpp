#include <iostream>
#include <stack>
#include "Graph.h"
void main(){
	Graph G;
	Type vdata;
	cout<<"���������붥�����ݣ���'ctrl+Z' 'ctrl+Z'��������\n";
	while(cin>>vdata){
		G.InsertVertex(vdata);
	}
	cin.clear();  //��Ϊ����״̬

	int v1 ,v2;
	weightType weight;
	cout<<"���������Ϣ(��ʽΪ v1 v2 weight):";
	
	cin>>v1>>v2>>weight;
	while(v1>=0&&v2>=0){
		G.InsertEdge(v1,v2,weight);
		cout<<"���������Ϣ(��ʽΪ v1 v2 weight):";
		cin>>v1>>v2>>weight;
	}


	int i;
	cout<<"ͼ�ж�������Ϊ:";
	for( i = 0 ;i <G.n(); i++)
		cout<<G.getVertex(i)<<" ";
	cout<<endl;

	cout<<"ͼ�б�����Ϊ:";
	for( i = 0 ;i <G.n(); i++){
		Edge edge = G.first(i);
		while(edge){
			cout<<"("<<edge->v1<<" "<<edge->v2<<" "<<edge->weight<<") ";
			edge = G.next(edge);
		}
	}
	cout<<endl;


	//Dijkstra_shortest_Path�㷨
	weightType *D = new weightType[ G.n() ]; 
	int *P = new int[ G.n() ];
	int s;    
	cout<<"�����������±�:";   cin>>s;
	Type sdata = G.getVertex(s);
	Dijkstra_shortest_Path(G,s,D,P);

	cout<<"����������·��,��ʽ���յ㣬���·�����ȣ����·����\n";
	stack<int> pathStack;
	Type vertexdata;
	for( i = 0; i<G.n(); i++){
		if(i==s) continue;		
		vertexdata = G.getVertex(i);
		if(D[ i ]>=100000){
			cout <<"�����"<<sdata<<"������"<<vertexdata<<"û��·��\n"; 
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




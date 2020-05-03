/*
 * graph.h
 *
 *  Created on: May 3, 2020
 *      Author: adrian-estelio
 */

#include "../header/graph.h"
#include <limits.h>
#include <stdlib.h>
#include "../header/queue.h"
#include <iostream>
double  prob(void){
	double result = rand();
	result= result/RAND_MAX;
return result ;
}
void insert_edge(AdjancencyList *g ,int x, int y, int weight,bool directed){
	edgenode *p;
	p = new edgenode;
	p ->weight = weight;
	p ->y =y;
	p ->next = g->edges[x];
	g->edges[x] = p;
	g->degree[x] ++;
	if (directed==false){
		insert_edge(g,y,x,weight,true);
	}
	else g->nedges++;
}
int graph::genCost(int initialCost,int  Range){
	double aux = rand();
	aux= aux/RAND_MAX *(Range -initialCost);
	int result = initialCost+static_cast<int>(aux);
	return result;
}

void graph::MonteCarlo(double density, int initialCost, int Range){
	int weight=0;
	for(int i=0; i< graph::List->nvertices;++i)
		for(int j = i+1;j<graph::List->nvertices;++j)
			if ((prob()<density)){
				weight = genCost(initialCost, Range);
				insert_edge(List, i, j,weight ,false);
			}
}


void graph::print_graph( void ){
	edgenode *p;
	for(int i=0; i< graph::List->nvertices;++i){
		std::cout<<i<<" :";
		p=graph::List->edges[i];
		while(p != NULL){
			std::cout<<"->"<<p->y;
			p = p->next;
		}
	std::cout<<std::endl;
	}
}
int *graph::ShortestPath(int start){
	int i;
	edgenode *p;
	int v;
	int w;
	int weight;
	p_queue Q; // xxx Dynamic allocation of size
	distance= new int[List->nvertices];
	for (i=0; i <List->nvertices;i++){
		distance[i] = INT_MAX;
		prev[i] = -1;
	}
	distance[start] =0;
	v = start;
	Q.insert(v,distance[v]);
	p = List->edges[v];
	while(Q.size()!=0){
		v = Q.extract_min();
		p = List->edges[v];
			while(p!=NULL){
				w = p->y;
				weight = p->weight;
				if (distance[w] > (distance[v]+ weight)){
					distance[w] = distance[v]+ weight;
					Q.insert(w,distance[w]);
					prev[w] =v;
				}
				p = p ->next;
			}
	}
	for(i = 0; i < List->nvertices;i ++)
		if(distance[i] ==INT_MAX)
			distance[i] =-1;
return distance;
}

void graph::find_path(int start, int end){
	if ((start == end)||(end == -1)){
		putIn(start);
		std::cout<< std::endl;
	}
	else{
		find_path(start,prev[end]);
		putIn(end);
	}
}

void graph::putIn(int p){
	hops++;
	path[hops] = p;
}


/*
 * graph.h
 *
 *  Created on: May 3, 2020
 *      Author: Adrian Vazquez
 */

#include "../header/graph.h"
#include <limits.h>
#include <stdlib.h>
#include "../header/queue.h"
#include <time.h>

double  prob(void){
	double result = rand();
	result= result/RAND_MAX;
return result ;
}
void graph::insert_edge(int x, int y, int weight,bool directed){
	edgenode *p;
	p = new edgenode;
	p ->weight = weight;
	p ->y =y;
	p ->next = List->edges[x];
	List->edges[x] = p;
	List->degree[x] ++;
	if (directed==false){
		insert_edge(y,x,weight,true);
	}
	else List->nedges++;
}
int graph::genCost(int initialCost,int  Range){
	double aux = rand();
	aux= aux/RAND_MAX *(initialCost-Range);
	int result = initialCost+static_cast<int>(aux);
	return result;
}

void graph::MonteCarlo(double density, int initialCost, int Range){
	int weight=0;
	srand(time(0));
	for(int i=0; i< graph::List->nvertices;++i)
		for(int j = i+1;j<graph::List->nvertices;++j)
			if ((prob()<density)){
				weight = genCost(initialCost, Range);
				graph::insert_edge(i, j,weight ,false);
			}
}


void graph::print_graph( void ){
	edgenode *p;
	std::cout<<"Vertices :"<<List->nvertices<<std::endl;
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
int *graph::getPath(int u, int w){
	hops =0;
	find_path(u,w);
	return path;
}
int graph::getSize(int w){
	return distance[w];
}
void graph::primMST(){
	edgenode *p;
	bool intree[List->nvertices];
	int v;
	int w;
	int weight;
	p_queue q;
	for(int i = 0 ; i < List->nvertices; i++){
		intree[i] = false;
		distance[i] = INT_MAX;
		prev[i] = -1;
	}

	distance[0] = 0;
	v = 0;
	q.insert(v,distance[0]);
	while(q.size()!=0){
		v = q.extract_min();
		intree[v] = true;
		p = List->edges[v];
		while(p!= NULL){
			w = p->y;
			weight = p->weight;
			if((distance[w] > weight)&&(intree[w]==false)){
				distance[w] = weight;
				prev[w] = v;
				q.insert(w,distance[w]);
			}
			p = p->next;
		}
	}
}
void graph::init(int n, bool directed ){
	List= new AdjancencyList;
	int i;
	List->nvertices = n;
	List->nedges = 0;
	List->directed = directed;
	List->degree = new int[n];
	List->edges = new edgenode*[n];
	for (i=0; i<n; i++)
		List->degree[i] = 0;
	for (i=0; i<n; i++)
		List->edges[i] = NULL;
	distance = new int[n];
	prev = new int[n];
	path = new int[n];
	pathSize = 0;
	hops = 0;
}
void graph::initFromFile(std::string route){
	std::ifstream file(route);

	int count = 0;
	int vertices= 0;

	std::string line;
	while (std::getline(file,line)){
		std::istringstream iss(line);
			if (count ==0){
				count++;
				if(!(iss>>vertices))
					break;
				init(vertices,false);
			}
			else{
			int x, y, cost;
			if (!(iss>>x>>y>>cost)) break;
			insert_edge(x, y,cost, false);
			}
		}
	std::cout<<vertices<<" Vertices"<<std::endl;
	file.close();
}

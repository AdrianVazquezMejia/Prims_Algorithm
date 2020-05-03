/*
 * graph.h
 *
 *  Created on: May 3, 2020
 *      Author: adrian-estelio
 */
#include <stddef.h>
#ifndef HEADER_GRAPH_H_
#define HEADER_GRAPH_H_

struct edgenode {
	int y;
	int weight;
	struct edgenode *next;
};

typedef struct {
	edgenode **edges;
	int *degree;
	int nvertices;
	int nedges;
	bool directed;
}AdjancencyList;

class graph{
public:

	graph(int n= 0, bool directed = false){
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
	};
	void init(int n = 0, bool directed = false);
	void print_graph(void);
	int  *getPath(int u, int w );
	int getSize(int w);
	void MonteCarlo(double density, int initialCost, int Range);
	int *ShortestPath(int start);


	~graph(){
		release();
	}

private:
	AdjancencyList *List;
	int *distance;
	int *path;
	int pathSize;
	int hops;
	int *prev;

	void find_path(int start, int end);
	void putIn(int p);
	int genCost(int initialCost,int  Range);
	void release(void){
		delete [] List->degree;
		delete [] List->edges;
		delete List;
		delete [] distance;
		delete [] prev ;
		delete [] path;
	}
};



#endif /* HEADER_GRAPH_H_ */

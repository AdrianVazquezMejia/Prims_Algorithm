/*
 * graph.h
 *
 *  Created on: May 3, 2020
 *      Author: adrian-estelio
 */
#include <stddef.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <fstream>
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
		init(n, directed);
		std::cout<<"constructed"<<std::endl;
	};
	graph(std::string route){
		initFromFile(route);
		std::cout<<"File Contructor"<<std::endl;
	}
	void initFromFile(std::string route);
	void init(int n = 0, bool directed = false);
	void print_graph(void);
	int  *getPath(int u, int w );
	int getSize(int w);
	void MonteCarlo(double density, int initialCost, int Range);
	int *ShortestPath(int start);
	AdjancencyList AdjancencyL(){
		return *List;
	};
	int *getDistance (){
		return distance;
	};
	int *getPrev(){
		return prev;
	};
	void primMST();
	void insert_edge(int x, int y, int weight,bool directed);
	~graph(){
		release();
		std::cout<<"Destructed"<<std::endl;
	}
	void release(void){
		delete [] List->degree;
		delete [] List->edges;
		delete List;
		delete [] distance;
		delete [] prev ;
		delete [] path;

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

};



#endif /* HEADER_GRAPH_H_ */

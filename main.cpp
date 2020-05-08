/*
 * main.cpp
 *
 *  Created on: May 2, 2020
 *      Author: adrian-estelio
 */



#include <iostream>
#include "header/graph.h"

#include <sstream>
#include <fstream>


using namespace std;
int main(){
	int n = 20;
	int *a;
	a = new int[n];
	graph g("data.txt");


	//Print the graph
	g.print_graph();

	// Calculate prim
	g.primMST();

	// Get previous array
	a = g.getPrev();
	cout<<"Parent array"<<endl;
	for(int i =0; i <n ; i++)
		cout<<" "<<a[i];
	cout<<endl;

	//get distance array
	int totalCost = 0;
	a = g.getDistance();
	cout<<"Distance array"<<endl;
	for(int i =0; i <n ; i++){
		cout<<" "<<a[i];
		totalCost +=a[i];
	}
	cout<<endl;

	cout<< "Total cost is NST: "<<totalCost<<endl;
	delete [] a;

	return 0;
}


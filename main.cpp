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
#include <ctime>
#include <chrono>

using namespace std;
int main(){
	auto start = std::chrono::system_clock::now();
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
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapse_seconds = end-start;
	std:: time_t end_time =std::chrono::system_clock::to_time_t(end);

	cout<<"Finished comuptation at :"<<std::ctime(&end_time)<<endl;
	cout<<"Elapsed time: "<< elapse_seconds.count()<<"s"<<endl;
	return 0;
}


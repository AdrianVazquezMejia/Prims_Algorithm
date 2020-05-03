/*
 * main.cpp
 *
 *  Created on: May 2, 2020
 *      Author: adrian-estelio
 */



#include <iostream>
#include "header/queue.h"
#include "header/graph.h"
using namespace std;
int main(){
	int n = 10;
	graph g(n, false);
	g.MonteCarlo(0.5,1,2);
	g.print_graph();
	return 0;
}


/*
 * queue.cpp
 *
 *  Created on: May 3, 2020
 *      Author: adrian-estelio
 */
#include "../header/queue.h"
#include <iostream>

int  p_queue::parent(int n){
	if (n==1)
		return -1;
	else
		return n/2;
}
void p_queue::insert(int x, int k){
	if (q->n >PQ_SIZE)
		std::cout<<"Warning, priority queue overflow "<<std::endl;
	else {
		q->n ++;
		q->q[q->n].value =x;
		q->q[q->n].key =k;
		bubble_up(q->n);
	}
}

void p_queue::bubble_up(int p){
	if (parent(p) == -1)
		return;
	if(q->q[parent(p)].key > q->q[p].key){
		swap(p,parent(p));
		bubble_up(parent(p));
	}
}
void p_queue::swap(int a , int b){
	queue_elem aux = p_queue::q->q[a];
	p_queue::q->q[a] = p_queue::q->q[b];
	p_queue::q->q[b] = aux;
}
void p_queue::make(int  *s , int *k ,int n){
	q->n = 0;
	for(int i =0; i<n; i++){
		insert(s[i],k[i]);
	}
}

void p_queue::q_print(void){
	for(int i =1; i<=p_queue::q->n; i++)
		std::cout<<" "<<p_queue::q->q[i].value;
	std::cout<<std::endl;
}

int p_queue::extract_min(void){
	int min = -1;   /* Minumun value*/
	if (q->n <=0)
		std::cout<<"Warning: empty priority queue"<<std::endl;
	else {

		min = q->q[1].value;
		q->q[1] = q->q[q->n];
		q->n = q->n -1;
		bubble_down(1);
	}
	return min;
}

void p_queue::bubble_down(int p){

	int c;
	int min_index;
	c = young_child(p);
	min_index = p;
	for(int i = 0;i<=1;i++)
		if (((c+i)<= q->n))
			if ((q->q[min_index].key > q->q[c+i].key))
				min_index= c+i;
	if (min_index!=p){
		swap(p, min_index);
		bubble_down(min_index);
	}
}
void p_queue::heapsort(int *s,int *k,int n){
	make(s,k,n);
	for(int i=0;i<n;i++)
		s[i] = extract_min();
}
int p_queue::young_child(int n){
	return 2*n;
}
int p_queue::size(void){
	return q->n;
}



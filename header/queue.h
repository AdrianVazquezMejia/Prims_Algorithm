/*
 * queue.h
 *
 *  Created on: May 3, 2020
 *      Author: adrian-estelio
 */

#ifndef QUEUE_H_
#define QUEUE_H_
const int PQ_SIZE = 500;
typedef struct {
	int key;
	int value;
}queue_elem;
typedef struct{
	queue_elem q[PQ_SIZE];
	int n;
}queue;

class p_queue{
public:
	p_queue(){
		q = new queue;
	}
	void insert(int x, int k);
	void make(int  *s , int *k, int n);
	void q_print(void);
	int extract_min(void);
	void heapsort(int *s,int *k,int n);
	int size(void);
	~p_queue(){
		delete q;
	}
private:
	int  parent(int n);
	void bubble_up(int p);
	void swap(int a , int b);
	void bubble_down( int p);
	int young_child(int n);
	queue *q;
};


#endif /* QUEUE_H_ */

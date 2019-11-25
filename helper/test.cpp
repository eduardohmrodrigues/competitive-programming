#include <cstdio>
#include "./competitive.h"

int main(){
	
	adjacency_matrix a(10);
	a.insert_edge(0, 0, 100);
	a.print();

	printf("\n");

	adjacency_list b(10);
	b.insert_edge(1, 2, 5);
	b.insert_edge(5, 7, 1);
	b.print();
	
	printf("\n");

	edge_list c;
	c.insert_edge(1, 2, 5);
	c.insert_edge(5, 7, 1);
	c.print();

	return 0;
}

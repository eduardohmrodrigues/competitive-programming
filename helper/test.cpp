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

	printf("\n");

	union_find u(10);
	u.union_set(1, 3);
	u.union_set(2, 4);
	u.union_set(5, 6);
	u.union_set(7, 5);
	u.union_set(2, 5);
	u.union_set(2, 1);
	u.print();
	
	u.full_path_compression();
	printf("\n");
	u.print();

	return 0;
}

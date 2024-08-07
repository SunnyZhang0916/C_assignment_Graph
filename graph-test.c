/*
 * @file graph-test.c
 * @author Sunny Zhang (dv21szg@cs.umu.se)
 * 
 * @brief DFS starts from 0 as the first vertex.
 * 
 * 
 * @date 2023-02-05
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "set.h"
#include "graph.h"

void dfs(graph *g, int now, int n, set *visited);
void print_graph(graph *g, int n);
void insert_edge_randomly(graph *g, int n, int m);


int main(void)
{
	srand(time(NULL));

	int n = 10, m = 20;

	graph *g = make_graph(n);
	
	insert_edge_randomly(g, n, m);

	set *visited = set_empty();

	printf("DFS order:");

	dfs(g, 0, 10, visited);

	printf("\n");

	set_destroy(visited);

	print_graph(g, n);

	destroy_graph(g, n);

	return 0;
}

/*
 * @brief DFS all the vertices by recursion
 * As it is graph, all the vertices should have at least one
 * adjacent vertex.
 * @param g the graph
 * @param now the current vertex to start
 * @param n all the nodes in graph
 * @param visited a set to save visited vertex
 */
void dfs(graph *g, int now, int n, set *visited)
{
	printf(" %d", now);

	set_insert(now, visited);
	
	int *neighbors = get_neighbors(g, now);

	if (neighbors == NULL) { // empty set
		return;
	}

	int n_nodes = number_of_nodes(g);

	for (int i = 0; i < n_nodes; i++) {

		if(set_member_of(i, g->array[now])){

			if (!set_member_of(i, visited)){
				
				dfs(g, i, n_nodes, visited);
			
			} 
				
		}
	}

	free(neighbors);
}

/*
 * @brief Pint all the adjancent vertices of the current vertex
 * 
 * @param g the graph
 * @param n The number of all vertices
 */
void print_graph(graph *g, int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d:", i);

		int *neighbors = get_neighbors(g, i);

		if (neighbors != NULL) { // empty graph
			int n_neighbors = number_of_neighbors(g, i);

			for (int j = 0; j < n_neighbors; j++)
				printf(" %d", neighbors[j]);

			free(neighbors);
		}

		printf("\n");
	}
}

/*
 * @brief Inserts the edge randomly between two vertices
 * 
 * @param g the graph
 * @param n The source vertex is random
 * @param m The destination vertex is random
 */
void insert_edge_randomly(graph *g, int n, int m)
{
	for (int i = 0; i < m; i++) {
		insert_edge(g, rand() % n, rand() % n);
	}
}

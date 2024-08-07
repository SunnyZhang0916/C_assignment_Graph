/*
 * @file graph.c
 * @author Sunny Zhang (dv21szg@cs.umu.se)
 * 
 * @brief The unordered directed Graph is constructed by an array of
 * 		  set. Directed graph means the graph will have directed edge
 * 		  points from the first vertex in the pair and point to the 
 * 		  second vertex in the pair. 
 * 		  DFS traverses all the vertices and it is possible for the 
 * 		  neighbors of vertices are repetition.
 * 
 * @date 2023-02-05
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "set.h"
#include "graph.h"

graph *make_graph(int n)
{
	graph *g = malloc(sizeof(graph));

	g->amount = n;

	g->array = malloc(n * sizeof(vertex));

	for (int i = 0; i < n; i++)
		g->array[i] = set_empty();

	return g;
}

void insert_edge(graph *g, int u, int v)
{
	set_insert(u, g->array[v]);
	set_insert(v, g->array[u]);
}

int *get_neighbors(graph *g, int x)
{
	return set_get_values(g->array[x]);
}

int number_of_neighbors(graph *g, int x)
{
	return set_size(g->array[x]);
}

int number_of_nodes(graph *g)
{
	return g->amount;
}

void destroy_graph(graph *g, int n)
{
	for (int i = 0; i < n; i++) {
		set_destroy(g->array[i]);
	}

	free(g);
}

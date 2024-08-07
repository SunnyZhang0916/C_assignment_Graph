/**
 * @file graph.h
 * @author Sunny Zhang (dv21szg@cs.umu.se)
 * @brief The field is implemented as an array of set.
 * 		  Set is constructed as a Bitvector. 
 * 
 * @date 2023-02-05
 * 
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

/**
 * @struct Define the new name of data type be *vertex
 * @brief Vertex is declared as pointer of type set 
 */
typedef set *vertex;

/**
 * @struct Define the new name of data type be *graph
 * @brief Graph To store the information of vertex and the 
 *        amount of nodes.
 *        The array is to save the information of the node.
 */
struct graph{
	int amount;
	vertex *array;
};

typedef struct graph graph;

/**
 * @brief Create an empty graph
 * Create a graph with a number of vertex
 * @param n the number of vertex
 * @return graph with n empty set(Vertex)
 */
graph *make_graph(int n);

/**
 * @brief Inserts the edge between two vertex if they are 
 *        adjacent vertices.
 * 
 * @param g the graph
 * @param u the source vertex
 * @param v the destination vertex
 */
void insert_edge(graph *g, int u, int v);

/**
 * @brief Get the neighbors of the vertex
 * 
 * @param g the graph
 * @param x the vertex
 * @return int* The array stored the information of 
 *         vertex's adjacent vertices
 */
int *get_neighbors(graph *g, int x);

/**
 * @brief Get the number of the vertex
 * 
 * @param g the graph
 * @param x the vertex
 * @return Get the number of a vertex's adjacent vertices
 */
int number_of_neighbors(graph *g, int x);

/**
 * @brief Get the number of vertices
 * @param g the graph
 * @return Get the number of of all vertices in graph
*/
int number_of_nodes(graph *g);

/**
 * @brief Deallocate the graph
 * 
 * @param g the graph
 * @param n The number of all vertices
 */
void destroy_graph(graph *g, int n);

#endif /* GRAPH_H */

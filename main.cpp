/*
 * main.cpp
 *
 *  Created on: 24 Jan 2021
 *      Author: toan
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <algorithm>
#include <functional>
#include <queue>
#include "Graph.h"

int main() {
	Graph g{};
	g.add(0, 1, 4);

	g.add(0, 7, 8);
	g.add(1, 2, 8);
	g.add(1, 7, 11);
	g.add(2, 3, 7);
	g.add(2, 8, 2);
	g.add(2, 5, 4);
	g.add(3, 4, 9);
	g.add(3, 5, 14);
	g.add(4, 5, 10);
	g.add(5, 6, 2);
	g.add(6, 7, 1);
	g.add(6, 8, 6);
	g.add(7, 8, 7);

	g.printGraph();
	cout << "No. of vertices: " << g.V() << endl;
	cout << "No. of edges: " << g.E() << endl;
	cout << "Connected (0, 3)? " << g.adjacent(0, 3) << endl;
	cout << "Connected (0, 1)? " << g.adjacent(0, 1) << endl;
	cout << "Connected (1, 0)? " << g.adjacent(1, 0) << endl;

	set<int> neighbors_node_8 = g.neighbors(2);

	for (int i : neighbors_node_8)
		cout << i << " ";

	cout << "Remove edge (2,8)" << endl;
	g.deleteEdge(8, 2);
	g.printGraph();
	cout << "No. of vertices: " << g.V() << endl;
	cout << "No. of edges: " << g.E() << endl;
	neighbors_node_8 = g.neighbors(2);
	for (int i : neighbors_node_8)
		cout << i << " ";
	cout << "Weight (1,7): " << g.get_edge_value(1, 7) << endl;
	cout << "Weight (7,1): " << g.get_edge_value(7, 1) << endl;

	cout << "Update weight " << endl;
	g.set_edge_value(1, 7, 20);
	g.printGraph();

	return 0;
}




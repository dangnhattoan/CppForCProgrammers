/*
 * Graph.h
 *
 *  Created on: 24 Jan 2021
 *      Author: toan
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <set>

using namespace std;

class GraphEdge {
	public:
		GraphEdge(int start_ver, int end_ver, int weight = -1) :
			start_ver(start_ver), end_ver(end_ver), weight(weight){}

		/*Get weight*/
		int get_weight() const { return weight;}
		int get_start() const {return this->start_ver;}
		int get_end() const {return this->end_ver;}

		void set_weight(int weight) {this->weight = weight;}

	private:
		int start_ver, end_ver;
		int weight;
};

/* Using the STL vector to store the GraphEdges*/
class Graph {
public:
	/*Constructor*/
	Graph(vector<GraphEdge> edgesList = {}, vector<int> nodeValues = {}) :
		nodeValues(nodeValues), edgeLists(edgesList) {}

	/*Return the number of vertices in the graph*/
	int V() const {
		set<int> vertice_set{};
		for (GraphEdge edge : this->edgeLists)
		{
			vertice_set.insert(edge.get_start());
		}
		return vertice_set.size();
	}

	/*Return the number of edges in the graph*/
	size_t E() const
	{
		return this->edgeLists.size();
	}

	/*Test whether there is an edge from node x to node y*/
	bool adjacent(int x, int y) const;

	/*List all nodes y such that there is an edge from x to y*/
	set<int> neighbors(int x) const;

	/*Adds to Graph the edge from x to y, if it is not there*/
	void add(int x, int y);
	void add(int x, int y, int weight);

	/*Removes the edge from x to y, if it is there*/
	void deleteEdge(int x, int y);

	/*Print graph*/
	void printGraph() const;

	/*Node value is an integer type*/
	int get_node_value(int x) const {
		try {
			return this->nodeValues.at(x);
		}catch (out_of_range& oor) {
			return 0;
		}
	}

	/*Set node value*/
	void set_node_value(int x, int a) {
		try {
			nodeValues.at(x) = a;
		}catch (out_of_range& oor) {
			cerr << "Out of range error: " << oor.what() << endl;
		}
	}

	/*Get edge value*/
	int get_edge_value(int x, int y) const;

	/*Set edge value*/
	void set_edge_value(int x, int  y, int weight);

private:
	vector<int> nodeValues;
	vector<GraphEdge> edgeLists;
};

#endif /* GRAPH_H_ */

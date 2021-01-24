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

template <class T, class W>
class GraphEdge {
	public:
		GraphEdge(T start_ver, T end_ver, W weight = -1) :
			start_ver(start_ver), end_ver(end_ver), weight(weight){}

		/*Get weight*/
		W get_weight() const { return weight;}
		T get_start() const {return this->start_ver;}
		T get_end() const {return this->end_ver;}

		void set_weight(W weight) {this->weight = weight;}

	private:
		T start_ver, end_ver;
		W weight;
};

/* Using the STL vector to store the GraphEdges*/
template <class T, class W>
class Graph {
public:
	/*Constructor*/
	Graph(vector<GraphEdge<T, T>> edgesList = {}, vector<W> nodeValues = {}) :
		nodeValues(nodeValues), edgeLists(edgesList) {}

	/*Return the number of vertices in the graph*/
	int V() const {
		set<int> vertice_set{};
		for (GraphEdge<T, int> edge : this->edgeLists)
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
	bool adjacent(T x, T y) const;

	/*List all nodes y such that there is an edge from x to y*/
	set<T> neighbors(T x) const;

	/*Adds to Graph the edge from x to y, if it is not there*/
	void add(T x, T y);
	void add(int x, int y, int weight);

	/*Removes the edge from x to y, if it is there*/
	void deleteEdge(T x, T y);

	/*Print graph*/
	void printGraph() const;

	/*Node value is an integer type*/
	int get_node_value(T x) const {
		try {
			return this->nodeValues.at(x);
		}catch (out_of_range& oor) {
			return 0;
		}
	}

	/*Set node value*/
	void set_node_value(T x, int a) {
		try {
			nodeValues.at(x) = a;
		}catch (out_of_range& oor) {
			cerr << "Out of range error: " << oor.what() << endl;
		}
	}

	/*Get edge value*/
	T get_edge_value(T x, T y) const;

	/*Set edge value*/
	void set_edge_value(T x, T  y, W weight);

private:
	vector<int> nodeValues;
	vector<GraphEdge<T, W>> edgeLists;
};

#endif /* GRAPH_H_ */

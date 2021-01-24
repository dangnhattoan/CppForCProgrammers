//============================================================================
// Name        : Graph.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Graph.h"

using namespace std;
/*Operator overloading of GraphEdge*/
template <class T, class W>
ostream& operator<<(ostream& os, const GraphEdge<T, W>& edge)
{
	os << edge.get_start() << "--" << edge.get_end() << ": " << edge.get_weight();
	return os;
}

template <class T, class W>
bool operator==(const GraphEdge<T, W>&lhs, const GraphEdge<T, W>&rhs)
{
	set<T> node{lhs.get_start(), lhs.get_end()};
	node.insert(rhs.get_start());
	node.insert(rhs.get_end());
	return node.size() == 2 ? true : false;
}

template <class T, class W>
bool Graph<T, W>::adjacent(T x, T y) const
{
	for (GraphEdge<T, W> edge : this->edgeLists)
	{
		if (edge == GraphEdge<T, W>{x, y})
			return true;
	}
	return false;
}

template <class T, class W>
set<T> Graph<T, W>::neighbors(T x) const
{
	set<T> neighbors;
	for (GraphEdge<T, W> edge : this->edgeLists)
	{
		if (edge.get_end() == x) neighbors.insert(edge.get_start());
		if (edge.get_start() == x) neighbors.insert(edge.get_end());
	}
	return neighbors;
}

template <class T, class W>
void Graph<T, W>::add(T x, T y)
{
	this->edgeLists.push_back(GraphEdge<T, W>{x, y});
}

template <class T, class W>
void Graph<T, W>::add(int x, int y, int weight)
{
	GraphEdge<T, W> edge{x, y, weight};
	this->edgeLists.push_back(edge);
}

template <class T, class W>
void Graph<T, W>::deleteEdge(T x, T y)
{
	GraphEdge<T, W> remove_edge{x,y};
	for (size_t i = 0; i < this->edgeLists.size(); i++)
	{
		if (this->edgeLists.at(i) == remove_edge)
			this->edgeLists.erase(this->edgeLists.begin() + i);
	}
}

template <class T, class W>
void Graph<T, W>::printGraph() const
{
	for(GraphEdge<T, W>edge : this->edgeLists)
		cout << edge << endl;
}

template <class T, class W>
T Graph<T, W>::get_edge_value(T x, T y) const {
	GraphEdge<T, W> edge {x, y};
	for (size_t i = 0; i < this->edgeLists.size(); i++)
	{
		if(this->edgeLists[i] == edge)
			return this->edgeLists[i].get_weight();
	}
	return -1;
}

template <class T, class W>
void Graph<T, W>::set_edge_value(T x, T  y, W weight)
{
	GraphEdge<T, W> set_edge{x, y};
	for (GraphEdge<T, W>&edge : this->edgeLists)
	{
		if (edge == set_edge)
		{
			edge.set_weight(weight);
			break;
		}
	}
}

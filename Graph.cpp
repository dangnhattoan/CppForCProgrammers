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

ostream& operator<<(ostream& os, const GraphEdge& edge)
{
	os << edge.get_start() << "--" << edge.get_end() << ": " << edge.get_weight();
	return os;
}


bool operator==(const GraphEdge&lhs, const GraphEdge&rhs)
{
	set<int> node{lhs.get_start(), lhs.get_end()};
	node.insert(rhs.get_start());
	node.insert(rhs.get_end());
	return node.size() == 2 ? true : false;
}


bool Graph::adjacent(int x, int y) const
{
	for (GraphEdge edge : this->edgeLists)
	{
		if (edge == GraphEdge{x, y})
			return true;
	}
	return false;
}


set<int> Graph::neighbors(int x) const
{
	set<int> neighbors;
	for (GraphEdge edge : this->edgeLists)
	{
		if (edge.get_end() == x) neighbors.insert(edge.get_start());
		if (edge.get_start() == x) neighbors.insert(edge.get_end());
	}
	return neighbors;
}


void Graph::add(int x, int y)
{
	this->edgeLists.push_back(GraphEdge{x, y});
}


void Graph::add(int x, int y, int weight)
{
	GraphEdge edge{x, y, weight};
	this->edgeLists.push_back(edge);
}


void Graph::deleteEdge(int x, int y)
{
	GraphEdge remove_edge{x,y};
	for (size_t i = 0; i < this->edgeLists.size(); i++)
	{
		if (this->edgeLists.at(i) == remove_edge)
			this->edgeLists.erase(this->edgeLists.begin() + i);
	}
}


void Graph::printGraph() const
{
	for(GraphEdge edge : this->edgeLists)
		cout << edge << endl;
}


int Graph::get_edge_value(int x, int y) const {
	GraphEdge edge {x, y};
	for (size_t i = 0; i < this->edgeLists.size(); i++)
	{
		if(this->edgeLists[i] == edge)
			return this->edgeLists[i].get_weight();
	}
	return -1;
}


void Graph::set_edge_value(int x, int  y, int weight)
{
	GraphEdge set_edge{x, y};
	for (GraphEdge&edge : this->edgeLists)
	{
		if (edge == set_edge)
		{
			edge.set_weight(weight);
			break;
		}
	}
}

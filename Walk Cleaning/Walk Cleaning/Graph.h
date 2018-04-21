#define GRAPH_H
#ifdef GRAPH_H

#include <sstream>
#include <assert.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "edge1.h"

using namespace std;

class Graph
{
public:
	vector <Edge>theGraph;
	int size;
	vector<vector<int>> adjmatrix;
	

	Graph(string filepath) 
	{
		ifstream fin(filepath);
		string line;
		getline(fin, line);
		size = (int)line[0];
		
	
		for (int i = size; i < size; i++)
		{
			for (int j = size; j < size; j++)

		}
		
		while (getline(fin, line))
		{
			Edge newedge;
			newedge.set(line[0], line[1]);
			theGraph.push_back(newedge);

		}



	};

	void computeTour(ofstream output)
	{

	};




	~Graph();

private:

};

Graph::~Graph()
{
}

#endif // Graph_H

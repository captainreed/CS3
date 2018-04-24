#define GRAPH_H
#ifdef GRAPH_H

#include <sstream>
#include <assert.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include "edge1.h"


using namespace std;

class Graph
{
public:
	vector <Edge> edgeList;
	int size;
	vector<vector<int>> adjmatrix;
	
	Graph(string filepath) 
	{
		ifstream fin(filepath);
		string line;
		if (!fin.is_open()) {
			cout << "aint no file up in here" << endl;
			return;
		}

		getline(fin, line);

		for (int i = 0; line[i] != ' '; i++)
		{
			size = ((int)line[0] - '0')*pow(10,i);
		}
		

		vector<int> secondary(size, -1);
		adjmatrix.resize(size, secondary);
		while (getline(fin, line))
		{
			Edge newedge;
			if (line != "") 
			{
				newedge.set(line[0], line[2]);
				edgeList.push_back(newedge);
				addEdge(newedge);
			}
		}
		fin.close();
	};

	void addEdge(Edge e1)
	{
		adjmatrix[e1.fromNode][e1.toNode] = 1;
		adjmatrix[e1.toNode].at(e1.fromNode) = 1;
	}
	void printAdjMatrix()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				int out = adjmatrix[i][j];
				cout << out;
			}
			cout << "" << endl;
		}
	}
	void pringEdgeList()
	{
		for (int i = 0; i < edgeList.size(); i++)
		{
			cout << edgeList[i].toString() << endl; 
		}
	}

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

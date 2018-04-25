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
		
		int edgeCount = 0;
		vector<int> secondary(size, -1);
		adjmatrix.resize(size, secondary);
		while (getline(fin, line))
		{
			Edge newedge;
			if (line != "") 
			{
				newedge.set(line[0], line[2]);
				newedge.edgeIndex = edgeCount;
				edgeList.push_back(newedge);
				addEdge(newedge);
			}
			edgeCount++;
		}
		fin.close();
	};

	bool eulerExists()
	{
		for (int i = 0; i < size; i++)
		{
			int nodect = 0;
			for (int j = 0; j < size; j++)
			{
				if (adjmatrix[i][j] > 0)
					nodect++;
			}
			if (nodect % 2 != 0)
				return false;
		}
		return true;
	};

	void addEdge(Edge e1)
	{
		adjmatrix[e1.fromNode][e1.toNode] = 1;
		adjmatrix[e1.toNode].at(e1.fromNode) = 1;
	};


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
	};
	void printEdgeList()
	{
		for (int i = 0; i < edgeList.size(); i++)
		{
			cout << edgeList[i].toString() << endl; 
		}
	};
	//this is the method that computes the euleran tour and prints it out
	void computeTour(ofstream output)
	{
		Edge startNode = edgeList[0];
		markCycles(startNode, 1);
		//add the edge to the path stack
		
	};

	void markCycles()
	{
		markCycles(edgeList[0], 1);
	};

	void markCycles(Edge e1, int cycle)
	{
		
		int start = e1.fromNode;
		edgeList[e1.edgeIndex].cycleID = cycle;
		Edge currentEdge = e1;

		//find an edge with a tonode of start
		//find the next available edge
		bool finished = false;
		for (int i = 0; i < edgeList.size() && !finished; i++)
		{
			if (currentEdge.toNode == start)
			{
				//youre done
				edgeList[i].cycleID = cycle;
				finished = true;
			}

			if ((edgeList[i].fromNode == currentEdge.toNode || edgeList[i].toNode == currentEdge.toNode) && edgeList[i].cycleID ==-1 && !finished)
			{
				edgeList[i].cycleID = cycle;
				currentEdge = edgeList[i];
			}

		}
		Edge nextEdge = nextFreeEdge();
		if (nextEdge.cycleID == -1)
		{
			markCycles(nextEdge, cycle + 1);
		}
		//mark as part of the cycyle
		//repeat until one of the nodes = start
		//pick a random unvisited edge and repeat
		//pick and edge
		
	};

	Edge nextFreeEdge()
	{
		Edge output;
		output.cycleID = -100;
		for (int i = 0; i < edgeList.size(); i++)
		{
			if (edgeList[i].cycleID == -1)
			{
				output = edgeList[i];
				return output;
			}
		}
		return output;
	};


	~Graph();

private:

};

Graph::~Graph()
{
};

#endif // Graph_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Graph.h"
#include <assert.h>
using namespace std;

void main ()
{  
	//ofstream fout;
	//fout.open("tourOut.txt");
	//assert(fout);


   Graph g("prog7A.txt");

   cout << "prog 7A edge list " << endl;
   g.markCycles();
   g.printEdgeList();
   cout << "prog 7A Matrix  " << endl;
   g.printAdjMatrix();
 
  //g.computeTour(fout);  // If I want the output to appear on console, I just make the parameter "cout"

  Graph g1("prog7B.txt");
  cout << "prog 7B edge list " << endl;
  g1.markCycles();
  g1.printEdgeList();
  cout << "prog 7B Matrix  " << endl;
  g1.printAdjMatrix();
 
  // g1.computeTour(fout);

  Graph g2("prog7C.txt");
  cout << "prog 7C edge list " << endl;
  g2.markCycles();
  g2.printEdgeList();
  cout << "prog 7C Matrix  " << endl;
  g2.printAdjMatrix();

   //g2.computeTour(cout);

   string wait;
   cin >> wait;
}
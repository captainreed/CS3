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

   if (g.eulerExists())
   {
	   cout << "prog 7A edge list " << endl;
	   g.pringEdgeList();
	   cout << "prog 7A Matrix  " << endl;
	   g.printAdjMatrix();
   }
   else
   {
	   cout << " no eulerian path";
   }
  // g.computeTour(fout);  // If I want the output to appear on console, I just make the parameter "cout"

   Graph g1("prog7B.txt");
   if (g1.eulerExists())
   {
   cout << "prog 7B edge list " << endl;
   g1.pringEdgeList();
   cout << "prog 7B Matrix  " << endl;
   g1.printAdjMatrix();
}
   else
   {
	   cout << " no eulerian path";
   }
  // g1.computeTour(fout);

   Graph g2("prog7C.txt");
   if (g2.eulerExists())
   {
   cout << "prog 7C edge list " << endl;
   g2.pringEdgeList();
   cout << "prog 7C Matrix  " << endl;
   g2.printAdjMatrix();
	  }
   else
   {
	   cout << " no eulerian path";
   }
   //g2.computeTour(cout);

   string wait;
   cin >> wait;
}
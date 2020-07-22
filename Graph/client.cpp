using namespace std;
#include <iostream>
#include "dgraph.h"
#include "stack.h"
//#include "slist.h"
// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
  // use the algorithm (read carefully) in the HW7
  // assignment sheet
  dgraph d;
  stack s;
  char vertex = ' ';
  int visitNum = 0;
  slist sl;

  d.fillTable();
  d.displayGraph();

  s.push( 'A' );
  //  s.displayAll();
  do
    {
      s.pop(vertex);
      //      s.displayAll();
      cout << "Popped " << vertex << endl;
      sl = d.findAdjacency(vertex);
      cout << "test" << endl;
      if (!d.isMarked(vertex))
	{
	  visitNum++;
	  // cout << visitNum << " " << vertex << endl;
	  d.visit(visitNum, vertex);
	  //	  sl = d.findAdjacency(vertex);
	  s.displayAll();
	  cout << endl << endl;
	  while (!sl.isEmpty())
	    {
	      //	      cout << endl << vertex << endl;
	      sl.deleteRear(vertex);
	      // cout << endl << vertex << endl;

	      if(!(d.isMarked(vertex)))
		{
		  //  cout << vertex << endl;
		  s.push(vertex);
		}

	    }
	}
      s.displayAll();
    }
  while(!(s.isEmpty()));
    {
      d.displayGraph();
    }
  /*  while (!(s.isEmpty()))
    {
      s.pop(vertex);
      cout << "Removed " << vertex << endl;

      if (!d.isMarked(vertex))
	{ visitNum++;
	  d.visit(visitNum, vertex);
	  cout << "Visited: " << visitNum << endl;
	  //visitNum++;

	  // Get adjecency list
	  /* if (d.findOutDegree(vertex) == 0)
	    cout << "reached an end" << endl;
	  else
	    sl = d.findAdjacency(vertex);

	  while (!(sl.isEmpty()))
	    {

	      sl.deleteRear(vertex);
	      if (!d.isMarked(vertex))
		{
		  cout << "Push " << vertex << endl;
		  s.push(vertex);
		}
	    }
	  cout << endl;

	}
    }
  d.displayGraph(); */


}

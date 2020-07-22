using namespace std;
#include <iostream>
#include "dgraph.h"
#include <fstream>

dgraph::dgraph() // initialize vertexName (blank) and visit numbers (0)    // initialize countUsed to be 0
{
  for (int i = 0; i < SIZE; i++)
    {
      Gtable[i].vertexName = ' ';
      Gtable[i].visit = 0;
    }
  countUsed = 0;
}
dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{}
void dgraph::fillTable()  // be sure to read from a file
{
  ifstream fin;
  fin.open("table.txt");

  char a;

  while(fin >> Gtable[countUsed].vertexName)
    {
      fin >> Gtable[countUsed].outDegree;
      for(int i = 0; i < Gtable[countUsed].outDegree; i++)
	{
	  fin >> a;
	  (Gtable[countUsed].adjacentOnes).addRear(a);
	}
      countUsed++;
    }
  fin.close();

}
void dgraph::displayGraph() // be sure to display
// in a really nice format -- all columns
{
  for(int i = 0; i < countUsed; i++)
    {
      // if (!(Gtable[i].adjacentOnes).isEmpty())
      cout << "Vertex:\t " << Gtable[i].vertexName << "\t";
      cout << "Out Deg:\t " << Gtable[i].outDegree << "\t";
      cout << "visit: \t " << Gtable[i].visit << "\t";
	if (!(Gtable[i].adjacentOnes).isEmpty())

	  //cout << "Adjacent:\t " << Gtable[i].adjacentOnes << endl;
	(Gtable[i].adjacentOnes).displayAll();
      else
	cout << "[EMPTY]" << endl;
    }
}
int dgraph::findOutDegree(char V)// throws exception
// does not use a loop
{
  int index = V - 65;

  /*  if(V < 65 || V > 90)
    {
      throw BadVertex();
      }*/
  if(index < countUsed && index >= 0)
    {
      return Gtable[index].outDegree;
    }
  throw BadVertex();
}
slist dgraph::findAdjacency(char V)// throws exception
// does not use a loop
{
  int index = V - 65;
  /* if(V < 65 || V > 90)
     throw BadVertex();*/
  if(index < countUsed && index >= 0)
    return Gtable[index].adjacentOnes;
  throw BadVertex();
}
void dgraph::visit(int x, char a)
{
  if (!(isMarked(a)))
    {
      int vertex = a - 65;

      Gtable[vertex].visit = x;
    }
}
bool dgraph::isMarked(char a)
{
  int vertex = a - 65;
  if (Gtable[vertex].visit != 0)
    return true;
  else
    return false;
}

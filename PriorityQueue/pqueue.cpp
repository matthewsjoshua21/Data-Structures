#include "pqueue.h"

// constructor
pqueue::pqueue()
{  count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue() {}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
void pqueue::insertjob(int j)
{
  // ** add the job j at the rear (update count)
  Q[count] = j;
  count++;
  trickleup(); // moves the job to the right place
}

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob()
{
  cout << "printing: " << Q[0] <<endl;
  reheapify();
}

// Purpose: to display all jobs
void pqueue::displayAll()
{ cout << "Jobs: " ;
  // ** loop to display jobs from slot 0 to slot count-1 horizontally. No need to show a tree format.
  for (int i = 0; i <= count-1; i++)
    cout << Q[i] << " ";
  cout << endl;
}

// Utility functions follow: ------------------


// Purpose: to make the very last job trickle up to the right location
void pqueue::trickleup()
{
  int x = count-1;  // the very last job location
  int p; // variable to hold parent of x
  // ** while x is > 0
  // compare Q[x] with the parent and if the parent is bigger swap & update x to be the parent . Otherwise stop.
  //  You can call getParent to get the location of the parent
  while (x > 0)
    {
      /* if (x%2 == 0)
	p = ((x - 2)/2);
      else
      p = ((x - 1)/2);*/
      p = getParent(x);
      if ( Q[x] < Q[p])
	{
	  int temp;
	  temp = Q[x];
	  Q[x] = Q[p];
	  Q[p] = temp;
	  x = p;
	}
      else
	return;

    }
}

// Purpose: find the location of the parent
// The child location is given.  Need to call even.
int pqueue::getParent(int child)
{  // ** return the parent location based on the child loc
  int parent; // declare a variahble to hold position of parent
  if (even(child)) // check if even or odd case
    parent = ((child - 2)/2);
  else
    parent = ((child - 1)/2);
  return parent;

}

// Purpose: is location i even? Important in finding its parent location
bool pqueue::even(int i)
{
  if ((i % 2) ==  0) return true; else return false; }


// Purpose: to reheapify the Pqueue after printing
void pqueue::reheapify()
{
  Q[0] = Q[count-1];  // move the last job to the front
  int x = 0;
  count--;
  // ** start X at the root and repeat the following:
  // Find the location of the smaller child if the child is
  // not off the tree yet
  // If the smaller child is smaller than the parent, swap
  //     and X becomes the smaller child
  // else stop to loop
   while (x < count-1)
    {
      int c = getSmallerchild(x);
      if (Q[x] > Q[c])
	{
	  int temp = Q[x];
	  Q[x] = Q[c];
	  Q[c] = temp;
	  x = c;

	}
      else
	return;
    }
}

// Purpose: to find the location of the smaller child
// where children at locations 2*i+1 and 2*i+2
int pqueue::getSmallerchild(int i)
{
  int childL,childR, smallest; // variables to hold the smallest values
// ** return the location of the smaller child
  if ((2*i)+2 <= count-1) //check if there are enough elements
    {
      childL = (2 * i)+1;
      childR = (2 * i)+2;
    }
  else if ((2*i)+1 <= count-1) //check if only left child exists
    {
      smallest = (2*i)+1;
      return smallest;
    }
  else // if position is already at smallest
    {
      smallest = i;
      return smallest;
    }
  if (Q[childL] > Q[childR])
    smallest = childR;
  else
    smallest = childL;
  return smallest;

}

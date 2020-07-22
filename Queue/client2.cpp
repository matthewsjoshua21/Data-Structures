using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: **
//Algorithm: **
int main()
{
  queue q; // ** "A", "B", "C" in the queue
  q.add("A");
  q.add("B");
  q.add("C");

  while (1==1)  // ** while loop -- indefinitely
    {
      try
	{
	  string added; // ** create a temporary string variable to hold the previous value


	  q.remove(added); // ** dequeue string to added to append to previous string
	  cout << added << endl;

	  if(!q.isFull()) //check for overflow
	    {
	      q.add(added + "A");
	      q.add(added + "B");
	      q.add(added + "C");
	    }
	}
      catch(queue::Underflow)
	{cerr << "Error:: Too few elements in the queue.." << endl; return 0;}  //display underflow message
      catch(queue::Overflow)
	{cerr << "Error:: The queue is full.." << endl; return 0;} //display overflow message
    }// end of loop

}

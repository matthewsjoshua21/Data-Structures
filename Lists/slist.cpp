using namespace std;
#include<iostream>
#include"slist.h"

// ** Make sure llist constructor and destructors have couts in them

//constructor for slist
slist::slist()
{ cout << "slist constructor:" << endl;
  Front = NULL;
  Rear = NULL;
  Count = 0;
}
//search fucntion for slist passed by value
int slist::search(el_t key)
{// create a pointer to search the list
  Node *nodePtr;
  nodePtr = Front; // set to front node
  int position = 1; // variable to to track position in list
  while (nodePtr != NULL) // loop to check each node
    {
      if (nodePtr -> Elem  == key) // check if the key matches the elem
	{
	  return position;
	}
      nodePtr = nodePtr -> Next;// increment the pointer
      position++; //incremnet position
    }
  return 0;
}
// function to replace an element at a postion passed by value
void slist::replace(el_t element, int pos)
{
  if (pos < 1 || pos > Count) //check if the pos is within scope
    throw OutOfRange(); // error
  Node  *nodePtr; //pointer to go throught the nodes
  node Ptr = Front; // set equal to front
  for (int i = 1; i < pos; i++) //loop through list incrementing pointer
    {
      nodePtr  = nodePtr -> Next;
    }
  nodePtr -> Elem = element; // replace at position
}
//bool function to compare two lists
bool s list::operator==(const slist& OtherOne)
{
  if (Count == OtherOne.Count) // check if the lists are of equal size
    {
      Node *nodePtr = OtherOne.Front; //set pointers to front elements of both lists
    Node *nodePtr2 = this -> Front;
    while (nodePtr != NULL && nodePtr2 != NULL) //loop through both lists
      {
	if (nodePtr -> Elem != nodePtr2 -> Elem) // check if the elements within the nodes are equal
	  {
	    return false;
	  }
	nodePtr = nodePtr -> Next; //inciment both pointers
	nodePtr2 = nodePtr2 -> Next;
      }
    return true;
    }
  return false;
}

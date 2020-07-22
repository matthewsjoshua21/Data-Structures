using namespace std;
#include<iostream>
#include"llist.h"

llist::llist()
{
  cout << "llist contstructor:" << endl;
  Front = NULL;
  Rear = NULL;
  Count = 0;
}

llist::~llist()
{
  cout << "llist destructer:" << endl;
  el_t x;
  while (!isEmpty())
    {
      deleteFront(x);
    }
}

//PURPOSE: Checks if the list is empty
//PARAMETER: none
bool llist::isEmpty()
{
  if (Count == 0)
    return true;
  else
    return false;
}

//PURPOSE: Displays contents of the list
//PARAMETER: none
void llist::displayAll()
{
  Node *nodePtr = Front;
  if (isEmpty())
    cout << "[EMPTY]" << endl;
 else
    {
      while(nodePtr)
	{
	  cout << nodePtr -> Elem << ", ";
	  nodePtr = nodePtr -> Next;
	}
      cout << endl;
    }
}

//PURPOSE: Adds a node to the end of the list
//PARAMETER: newNum
void llist::addRear(el_t NewNum)
{
  Node *newNode = new Node;
  newNode -> Next = NULL;
  newNode -> Elem = NewNum;

  if (!Rear)
    {
      Front = newNode;
      Rear = Front;
      Count++;
      return;
    }
  else
    {
      Rear -> Next = newNode;
      Rear = newNode;
      Count++;
    }
}

//PURPOSE: Adds a node to the front of the list
//PARAMETER: NewNum
void llist::addFront(el_t NewNum)
{
  Node *newNode = new Node;
  newNode -> Next = NULL;
  newNode -> Elem = NewNum;

  if (!Front)
    {
      Front = newNode;
      Rear = Front;
      Count++;
    }
  else
    {
      newNode -> Next = Front;
      Front = newNode;
      Count++;
    }
}

//PURPOSE: Removes an node from the front of the list
//PARAMETER: oldNum
void llist::deleteFront(el_t& OldNum)
{
  if (isEmpty())
    {
      throw Underflow();
    }
  else if (Count == 1)
    {
      OldNum = Front -> Elem;
      delete Front;
      Front = NULL;
      Rear = NULL;
      Count--;
      //return OldNum;
    }
  else
    {
      Node *nodePtr = Front;
      OldNum = Front -> Elem;
      nodePtr = Front -> Next;
      delete Front;
      Front = nodePtr;
      Count--;
      // return OldNum;
    }
}

//PURPOSE: Removes a node from the rear
//PARAMETER: OldNum
void llist::deleteRear(el_t& OldNum)
{
  if (isEmpty())
    {
      throw Underflow();
    }
  else if (Count == 1)
    {
      OldNum = Rear -> Elem;
      delete Rear;
      Front == NULL;
      Rear == NULL;
      Count--;
    }
  else
    {
      Node *nodePtr = Front;
      OldNum = Rear -> Elem;

      /*      for (int i = 1; i < Count; i++)
	nodePtr = nodePtr -> Next;
      */
      while (nodePtr->Next != Rear)
	nodePtr = nodePtr -> Next;
      delete Rear;

      Rear = nodePtr;
      nodePtr -> Next = NULL;

      Count--;
      // return OldNum;
    }
}

//PURPOSE: Removes a node a pos
//PARAMETER: I and OldNum
void llist::deleteIth(int I, el_t& OldNum)
{
  if (I > Count || I < 1)
    throw OutOfRange();
  else if (I == 1)
    deleteFront(OldNum);
  else if (I == Count)
    deleteRear(OldNum);
  else
    {
      Node *nodePtr = Front -> Next;
      Node *nodePrev = Front;
      for (int K = 1; K <= I-1; K++)
	{
	  nodePtr = nodePtr -> Next;
	  nodePrev = nodePrev -> Next;
	}
      nodePrev -> Next = nodePtr -> Next;
      OldNum = nodePtr -> Elem;
      delete nodePtr;
      Count--;
    }

}

//PURPOSE: Add node at pos
//PARAMETER: I and newNum
void llist::insertIth(int I, el_t newNum)
{
  if (I > Count+1 || I < 1)
    {
      throw OutOfRange();
    }
  else if ( I ==1 )
    {
      addFront(newNum);
    }
  else if ( I == Count+1 )
    {
      addRear(newNum);
    }
  else
    {
      Node *nodePrev = Front;
      Node *nodePtr = NULL;
      Node *newNode = new Node;
      newNode -> Elem = newNum;

      for (int K = 1; K <= I-1; K++)
	{
	  // nodePtr = nodePtr -> Next;
	  nodePrev = nodePrev -> Next;
	}

      nodePtr = nodePrev -> Next;
      nodePrev -> Next = newNode;
      newNode -> Next = nodePtr;
      Count++;
      /*      nodePtr = nodePrev -> Next;
      newNode -> Next = nodePtr;
      nodePrev -> Next = newNode;*/
    }

}

//PURPOSE: Copy constructor/ deep copy
//PARAMETER: Original
llist::llist(const llist& Original)
{
  Node *temp = Original.Front;
  Node *nodePtr = NULL;
  Front = new Node;
  nodePtr = Front;
  this -> Rear = NULL;
  this -> Count = 0;

  while (temp != NULL)
    {
      nodePtr -> Elem = temp -> Elem;
      temp = temp -> Next;

      if (temp)
        {
          nodePtr -> Next = new Node;
          nodePtr = nodePtr -> Next;
	  this -> Rear = nodePtr;
	  this -> Count++;
        }
      nodePtr -> Next = NULL;
    }
    /*  this -> Front = NULL;
  this -> Rear = NULL;
  this -> Count = 0;
  int x;

  if (&Original != this)
    {
      while (!this -> isEmpty())
	this -> deleteRear(x);

      Node *nodePtr;
      nodePtr = Original.Front;
      while (nodePtr != NULL)
	{
	  this -> addRear(nodePtr -> Elem);
	}
    }// end of if
  //  return *this;
  */
}

//PURPOSE: Overloaded operator for copying a list/deep copy
//PARAMETER: OtherOne
llist& llist::operator=(const llist& OtherOne)
{
  Node *temp = OtherOne.Front;
  Node *nodePtr = NULL;
  Front = new Node;
  nodePtr = Front;
  this -> Rear = NULL;
  this -> Count = 0;

  while (temp)
    {
      nodePtr -> Elem = temp -> Elem;
      temp = temp -> Next;

      if (temp != NULL)
	{
	  nodePtr -> Next = new Node;
	  nodePtr = nodePtr -> Next;
	  this -> Rear = nodePtr;
	  this -> Count++;
	}
      nodePtr -> Next = NULL;
      }
  /*
  int x;
  if (&OtherOne != this)  // if not the same
    {

      while (!this -> isEmpty())
	this -> deleteRear(x);
      Node *nodePtr;
      nodePtr = OtherOne.Front;
      while (nodePtr != NULL)
       {
	  this -> addRear(nodePtr -> Elem);
       }
    }// end of if
  return *this;
  */
}

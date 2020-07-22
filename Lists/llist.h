// alias el_t : element type definition
typedef int el_t;

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{

 protected:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

 public:

  // Exception handling classes
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes

  //check to see if the value of the first pointer is NULL
  bool isEmpty();

  // function to traverse the linked list and display all elements
  void displayAll();

  //function to add an element to the front of the linked list
  void addFront(el_t);

  //functionto add an element to the rear of the linked list
  void addRear(el_t);

  //function to delete the first element of the linked list
  void deleteFront(el_t&);

  //function to delete the last element of the linked list
  void deleteRear(el_t&);

  //function to delete an element at a position
  void deleteIth(int, el_t&);

  //function to insert an element at a position
  void insertIth(int, el_t);

  //Copy Constructor to allow pass by value and return by value
  llist(const llist&);

  //Overloading of =
  llist& operator=(const llist&);

};

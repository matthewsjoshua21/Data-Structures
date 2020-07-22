using namespace std;
#include <iostream>
#include "htable.h"

htable::htable()
{}

htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
int htable::hash(int key)
{
  return key % TSIZE;
}

// adds the element to the table and returns slot#
int htable::add(el_t element )
{
  int pos = hash(element.key);  // hash
  table[pos].addRear(element);
  return pos;
}
// finds element using the skey and returns the found element itself
// or a blank element
el_t htable::find(int skey)
{
  el_t E; // variable to hold and return element
 int pos = hash(skey); // hash
 el_t sElement;  // element to hold key
 sElement.key = skey; //set = to key
 E = table[pos].search2(sElement); // call slist's search2
 return E; // return
}

// displays the entire table with slot#s too
void htable::displayTable()
{
  for (int i = 0; i < 13; i++)
    { cout << i << ":" ;
      table[i].displayAll(); // call slist's displayAll
    }
}

using namespace std;
#include "htable.h"

int main()
{

  htable hTable;
  el_t empty;
  int inputKey = 0;
  string band = "";
  string album = "";
  string song = "";
  int year = 0;

  cout << "*******************************************************" << endl;
  cout << "* Enter All embarrasing music, when finsihed enter -1 *" << endl;
  cout << "* InputKey, Band, Song, Album, Year.                  *" << endl;
  cout << "*                                                     *" << endl;
  cout << "*                                                     *" << endl;
  cout << "*******************************************************" << endl;
  cout << endl;
  // condition to quit inputing
  while (inputKey != -1)
    {

      cout << "Enter Key: " ;
      cin >> inputKey;
      if (inputKey != -1)
	{ // enter the bands info
	  cout << "Enter Band: " ;
	  cin >> band;
	  cout << "Enter Song: " ;
	  cin >> song;
	  cout << "Enter Album: ";
	  cin >> album;
	  cout << "Enter Year: " ;
	  cin >> year;
	  // call elem to create a new object
	  el_t elem(inputKey, band, song ,album, year);
	  hTable.add(elem);
	}
    }

     // DisplayTable.
  hTable.displayTable();
  // search for an element
  int key = 0; // variable to hold hash key
  // condition to exit
  while (key != -1)
    {
      cout << "Look for? " << endl;
      cin >> key;

      if (key != -1)
	{
	  el_t found = hTable.find(key);
	  if (found == empty)
	    cout << key <<  " not Found" << endl;
	  else
	    cout << "Found: " << found <<  endl;

	}
    }

}

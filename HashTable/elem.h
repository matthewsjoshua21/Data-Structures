// 
//-----------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

class el_t
{
 private:
  int key;      // key
  string band;  // band name
  string song;  // song title
  string album;  // album name
  int year; // year
 public:

  el_t();  // to create a blank el_t object
  el_t(int, string, string, string, int); // to create an initialized el_t object

  bool operator==(el_t);  // overload == for search
  bool operator!=(el_t);  // overload != for search
  // In search == is used to compare node elements
  // but what does it mean for this client to compare
  // node elements?  

  // this overloads cout for the el_t object
  // This is a friend function since the receiver object is not el_t
  friend ostream& operator<<(ostream&, const el_t&);  
  
  friend class htable;  // client of this class is htable which needs access to the key part of el_t 

};


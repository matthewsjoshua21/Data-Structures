// updated elem to hold music information
//  
//----------------------------------------------------

#include "elem.h"

// blank element
el_t::el_t()
{
  key = 0;
  band = "";
  song = "";
  album = "";
  year = 0;
}

// initializing constructor to create an el_t object 
el_t::el_t(int akey, string aband, string asong, string aalbum, int ayear)
{
  key = akey;
  band = aband;
  song = asong;
  album = aalbum;
  year = ayear;
}
  
// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne)
{
  if (key == OtherOne.key) return true; else return false;
}

// overload != for search based on the key part only
bool el_t::operator!=(el_t OtherOne)
{
  if (key != OtherOne.key) return true; else return false;
}

// overload cout 
ostream& operator<<(ostream& os, const el_t& E)  
{  
  os << E.key << "+" << E.band << "+" << E.song << "+" << E.album << "+" << E.year;
  return os;  
}  

using namespace std;
#include <iostream>

// x is what we are looking for in L; first and last are slot numbers
int binarySearch(int L[], int x, int first, int last)
{
  int middle = (first + last)/2; // declare variable and assign it the middle value of the given array
  cout << "comparing against an element in slot " << middle << endl;
  if (x == L[middle]) // check if the element is the middle
    return middle;
  else  if (first == last) // add case for the element not existing
    return -1;// if first == last -1 is returned as a flag for the error message
  else if (x < L[middle]) // else if it is below the middle decreament the last element to shorten array
    last = middle - 1;
  else if (x > L[middle]) // else if it is above increament the value of first to shorten the array
    first = middle + 1;
  return binarySearch(L, x, first, last); // call the function recurrsivley
}


int main()
{
  int N = 10; // assign global varriable for ref to max value
  int A[N];
  int e;  // to look for this
  int first_1 = 0; // first is declared with the value of the first element address
  int last_1 = N-1; // last is declared with the value of max-1
  // fixed elements for A
  A[0] = 1; A[1]= 3; A[2]=5; A[3]= 7; A[4]=9; A[5]=11; A[6]=13;
  A[7] =15; A[8]= 17; A[9]= 19;

  cout << "What do you want to look for? ";
  cin >> e;

  // Call binarySearch here to look for e in A
  int respos = binarySearch(A, e, first_1, last_1);

  if (respos == -1) cout << "Element not found" << endl;
  else cout << "Found it in position " << respos+1 << endl;

}

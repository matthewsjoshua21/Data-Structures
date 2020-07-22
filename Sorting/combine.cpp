using namespace std;
#include <iostream>
#include <vector>

// combine two sorted lists A and B into R
// displays comparison every time it is done
void combine( vector<int> A, vector<int> B, vector<int> &R )
{
  int ia = 0; // declare variables to use
  int ib = 0;
  while ( ia < A.size() && ib < B.size() ) // check if both index are withing the vectors
    {

      if ( A[ia] < B[ib] ) // compare values befre inserting into vector
	{
	  R.push_back(A[ia]);
	  ia++;
	}
      else
	{
	  R.push_back(B[ib]);
	  ib++;
	}
      cout << "comparison" << endl;
    }
      //     ** // be careful -- R comes in as an empty vector
  if (ia < A.size()) // continue through the remainder of the vectors if any were missed by the first condition
    {
      for (; ia < A.size(); ia++)
	R.push_back(A[ia]);
    }
  else
    {
      for (; ib < B.size(); ib++)
	R.push_back(B[ib]);
    }
}


int main()
{
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  int N;  // how many elements in each of L1 and L2
  int e;  // for each element

  cout << "How many elements in each list?" << endl;
  cin >> N;

  cout << "List1"  << endl;
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L1.push_back(e);}

  cout << "List2"  << endl;
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L2.push_back(e);}


  // call combine here to combine L1 and L2 into L3
  // **
  combine(L1, L2, L3);

  cout << "The result is: ";
  for (int i = 0; i < N*2; i++)
    { cout << L3[i]; } cout << endl;

}// end of main

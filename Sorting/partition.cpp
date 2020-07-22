#include<iostream>
using namespace std;

// partitions the array a into smaller than pivot and others.
// f is the beginning of the section to be partitioned
// r is the end of the section to be partitioned
// return the first slot of the Large section
int partition(int pivot, int a[], int f, int r)
{
  int left = f; // pointer from the left
  int right = r; // pointer from the right
  int p = pivot;
  // loop for finding out of place pairs and swap them
  // ** until the left and right cross
  //    if left OK, move left
  //    if right OK, move right
  //    if both are bad, swap
  if ( left != right) // check if there is more than one element
    {
      while (left < right) // loop until pointers cross
	{
	  while (a[left] < p) // check the calue of left against the pivot
	    left++;
	  while (a[right] >= p) // check the value of right against the pivot
	    right--;
	  if ( left <= right) // when both fail a swap is performed on left and right
	    {
	      int tmp = a[left];
	      a[left] = a[right];
	      a[right] = tmp;
	      left++;
	      right--;
	    }
	}
    }
  if (left == 0) // special case for when the first element is already the smallest
    return left +1;
  return left; // return the left pointer

  // return the partition point where
  // those smaller than pivot are before what is returned
  // ** there is a special cases and a regular case
}

int main()
{
  int x;  // number of elements
  int nums[10];
  cout << "How many elements? (must be less than 10) ";
  cin >> x;
  cout << "Enter elements one per line.." << endl;
  for (int i = 0; i < x; i++)
    { cin >> nums[i]; }

  // the pivot is always the first element
  cout << "Ok the pivot is " << nums[0] << endl;

  int part = partition(nums[0], nums, 0, x-1);

  cout << "Results..." << endl;
  // display up to the partition without endl
  for (int i = 0; i < part; i++)
    cout << nums[i];

  cout << "|";
  // display from the partition on.. without endl
  for (int i = part; i < x; i++)
    cout << nums[i];

  cout << endl;

}

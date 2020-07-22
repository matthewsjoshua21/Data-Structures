using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: to evaluate postfix expressions from user entered strings
//Algorithm: **
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression

  cout << "type a postfix expression: " ;
  cin >> expression;

  int i = 0;  // character position within expression
  char item;  // one char out of the expression

  int box1;  // receive things from pop
  int box2;  // receive things from pop

  while (expression[i] != '\0')
    {
     try
       {
	 item = expression[i];  // current char

	 // ** do all the steps in the algorithm given in Notes-1


       } // this closes try
      // Catch exceptions and report problems and quit the program now (exit(1)).
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow)
	{** }
      catch (stack::Underflow)
	{** }
      catch (char const* errormsg ) // for invalid item case
	{** }

      // go back to the loop after incrementing i
      **
    }// end of while

 // After the loop successfully completes:
 // Pop the result and show it.
   **
 // If anything is left on the stack, an incomplete expression
 // was found so inform the user.
   **

}// end of the program

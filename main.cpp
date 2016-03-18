#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

#include "Infix.h"

using namespace std;

int main()
{
  Infix obj;
  string newEntry;
  char input1, input2;

  cout << "Would you like to evaluate an expression? (y/n)" << endl;
  cin >> input1;

  if(input1 == 'y' || input1 == 'Y')
    do
      {
	cout << "Enter an expression: ";
	cin >> newEntry;

	cout << newEntry << " = "
	     << obj.getExpEval(newEntry)
	     << endl;

	cout << "Would you like to evaluate another expression? (Y or N): " << endl;
	cin >> input2;
      }
    while(input2 == 'Y' || input2 == 'y');
  else
    cout << "Pancakes." << endl;

}

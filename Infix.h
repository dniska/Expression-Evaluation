#ifndef _INFIX
#define _INFIX
#include <string>

#include "StackInterface.h"

using namespace std;

class Infix {
 private:
  string Exp;

 public:
  // Default ctor                                                               
  Infix();

  void setExp(const string& newEntry);

  string getExp();

  int getExpEval(string& newEntry);

  void execute();

  int operand1, operand2, result;

  char operator1;
};

//#include "Infix.cpp"

#endif

#include <cstdlib>
#include <string>
#include <stack>
#include <cmath>
#include <iostream>

using namespace std;

#include "Infix.h"
#include "LinkedStack.h"
#include "DivisionExc.h"

LinkedStack<int> valueStack;
LinkedStack<char> operatorStack;

int getPrec(char c) {

  if(c == '(' || c == ')')
    return 0;
  else if(c == '+' || c == '-')
    return 1;
  else if(c == 'x' || c == '*' || c == '/')
    return 2;
  else
    return -1;
}

Infix::Infix() {}

void Infix::setExp(const string& newEntry) {

  Exp = newEntry;
}
string Infix::getExp() {

  return Exp;
}

int Infix::getExpEval(string& Exp) {

  for(int i = 0; i < Exp.length(); ++i)
    {
      if(Exp[i] >= '0' && Exp[i] <= '9')
	{
	  valueStack.push((int)Exp[i] - '0');
	}
      else if(Exp[i] == '(')
	{
	  operatorStack.push(Exp[i]);
	}
      else if(Exp[i] == 'x' || Exp[i] == '+' || Exp[i] == '/' || Exp[i] == '-' || Exp[i] == '*')
	{
	  if(operatorStack.isEmpty() || getPrec(Exp[i]) > getPrec(operatorStack.peek()))
	    {
	      operatorStack.push(Exp[i]);
	    }
	  else
	    {
	      while(!operatorStack.isEmpty() && getPrec(Exp[i]) <= getPrec(operatorStack.peek()))
		{
		  execute();
		}
	      operatorStack.push(Exp[i]);
	    }
	}
      else if(Exp[i] == ')')
	{
	  while(operatorStack.peek() != '(')
	    {
	      execute();
	    }
	  operatorStack.pop();
	}
    }
  while(!operatorStack.isEmpty())
    {
      execute();
    }
  return valueStack.peek();
}

void Infix::execute() {

  operand1 = valueStack.peek();

  valueStack.pop();

  operand2 = valueStack.peek();

  valueStack.pop();

  operator1 = operatorStack.peek();

  operatorStack.pop();

  if(operator1 == '+')
    result = operand1+operand2;
  else if(operator1 == '-')
    result = operand1-operand2;
  else if(operator1 == '*' || operator1 == 'x')
    result = operand1*operand2;
  else if(operator1 == '/')
    result = operand1/operand2;
  else
    cout << "Invalid operator." << endl;

  valueStack.push(result);
}

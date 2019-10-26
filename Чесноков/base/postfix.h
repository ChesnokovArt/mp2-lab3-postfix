#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include "stack.h"
#include <string>
#include <map>

using namespace std;

enum Postfix_Exception
{
	Invalid_Infix,
	Division_By_Zero
};

class TPostfix
{
  string infix;
  string postfix;
public:
	TPostfix();
	TPostfix(string s);
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	string ToPostfix();
	void SetNewInfix(string s);
	double Calculate(); // Ввод переменных, вычисление по постфиксной форме

private:    // вспомогательные функции
	// узнать приоретет операции
	int priority(char c);
	// заполнить переменные в выражение значениями
	map<char, double> read_vars();
};

#endif

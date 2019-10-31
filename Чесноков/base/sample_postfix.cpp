#include "postfix.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  string expression;
  double res;
  char c;
  setlocale(LC_ALL, "Russian");
  start:
  try
  {
	  do
	  {
		  cout << "Введите арифметическое выражение: ";
		  getline(cin, expression);
		  TPostfix postfix(expression);
		  cout << "Арифметическое выражение: " << postfix.GetInfix() << endl;
		  postfix.ToPostfix();
		  cout << "Постфиксная форма: " << postfix.GetPostfix() << endl;
		  res = postfix.Calculate();
		  cout << "Результат вычислений: " << res << endl;
		  cout << "Чтобы выйти введите q" << endl;
		  cin >> c;
		  std::cin.ignore(32767, '\n');
	  } while (c != 'q');
  }

  catch (const Postfix_Exception e)
  {
	  switch (e)
	  {
	  case Postfix_Exception::Invalid_Infix:
		  cout << "Некорректный ввод\n";
		  goto start;
	  case Postfix_Exception::Division_By_Zero:
		  cout << "Деление на ноль\n";
		  std::cin.ignore(32767, '\n');
		  goto start;
	  default:
		  break;
	  }
  }
  

  return 0;
}

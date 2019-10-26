#include "postfix.h"
#include "stack.h"
#include <algorithm>
#include <iostream>

TPostfix::TPostfix()
{
}

TPostfix::TPostfix(string s)
{
	// удаление пробелов
	s.erase(remove_if(s.begin(), s.end(), isspace), s.end());
	// проверка на корректность и перевод всех символов в заглавные
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (islower(s[i]))
		{
			s[i] = toupper(s[i]);
		}
		// проверка на допустимые символы
		if (!(s[i] >= 'A' && s[i] <= 'Z' || s[i] == '(' || s[i] == ')'
			|| s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')) throw Invalid_Infix;
		if (s[i] == '(')
			count1++;
		if (s[i] == ')')
			count2++;
	}
	// простая проверка на валидность скобок
	if (count1 != count2)
	{
		throw Invalid_Infix;
	}
	infix = s;
}

string TPostfix::ToPostfix()
{
	// максимальный размер стека это длина инфиксной строки
	TStack<char> stack1(infix.length());
	TStack<char> stack2(infix.length());
	char top;
	int m = infix.length();
	for (int i = 0; i < m; i++)
	{
		if ((infix[i] >= 'A') && (infix[i] <= 'Z'))
		{
			stack1.Push(infix[i]);
			continue;
		}
		if (infix[i] == '(')
		{
			stack2.Push(infix[i]);
			continue;
		}
		if (infix[i] == ')')
		{
			while ((top = stack2.Pop()) != '(')
			{
				stack1.Push(top);
			}
			continue;
		}
		if (!stack2.IsEmpty())
		{
			top = stack2.Pop();
			if (priority(infix[i]) > priority(top))
			{
				stack2.Push(top);
				stack2.Push(infix[i]);
				continue;
			}
			else
			{
				stack2.Push(top);
				while (priority(top) >= priority(infix[i]))
				{
					stack2.Pop();
					stack1.Push(top);
					if (stack2.IsEmpty()) break;
					top = stack2.Pop();
					stack2.Push(top);
				}
				stack2.Push(infix[i]);
				continue;
			}
		}
		else
		{
			stack2.Push(infix[i]);
			continue;
		}
	}
	while (!stack2.IsEmpty())
	{
		char a = stack2.Pop();
		stack1.Push(a);
	}
	postfix = "";
	while (!stack1.IsEmpty())
	{
		char a = stack1.Pop();
		postfix = a + postfix;
	}
	return postfix;
}

void TPostfix::SetNewInfix(string s)
{
	TPostfix::TPostfix(s);
}

double TPostfix::Calculate()
{	
	map<char, double> values = read_vars();
	TStack<double> stack(postfix.length());  // максимальный размер стека - длина строки постфиксной формы
											 // должно хватить даже в самом худшем случае
	int m = postfix.length();
	double x, y, Result;
	for (int i = 0; i < m; i++)
	{
		if ((postfix[i] >= 'A') && (postfix[i] <= 'Z'))
		{
			stack.Push(values[postfix[i]]);
		}
		if (postfix[i] == '+')
		{
			x = stack.Pop();
			y = stack.Pop();
			Result = y + x;
			stack.Push(Result);
		}
		if (postfix[i] == '-')
		{
			x = stack.Pop();
			y = stack.Pop();
			Result = y - x;
			stack.Push(Result);
		}
		if (postfix[i] == '*')
		{
			x = stack.Pop();
			y = stack.Pop();
			Result = y * x;
			stack.Push(Result);
		}
		if (postfix[i] == '/')
		{
			x = stack.Pop();
			y = stack.Pop();
			if (x == 0)
			{
				throw Division_By_Zero;
			}
			Result = y / x;
			stack.Push(Result);
		}
	}
	Result = stack.Pop();
	return Result;
}

int TPostfix::priority(char c)
{
	switch (c)
	{
	case '(':
		return 1;
		break;
	case '+':
		return 2;
		break;
	case '-':
		return 2;
		break;
	case '*':
		return 3;
		break;
	case '/':
		return 3;
		break;
	}
	return 0;
	return 0;
}

map<char, double> TPostfix::read_vars()
{
	map<char, double> values;
	double value;
	for (const char c : postfix)
	{
		if ((c >= 'A') && (c <= 'Z'))
		{
			if (values.count(c) == 0)
			{
				cout << "Input:" << c << endl;
				cin >> value;
				values[c] = value;
			}
		}
	}
	return values;
}

#ifndef __STACK_H__
#define __STACK_H__

enum class Stack_Exception
{
	Invalid_Size,
	Stack_OverFlow,
	Stack_Empty
};
const int MaxStackSize = 100;

template <class T>
class TStack
{
  T *pMem;
  int size;
  int top;
 
public:
	TStack(int _size);
	TStack(const TStack<T>& s);

  void Push(T a);
  T Pop();
  bool IsFull() const;
  bool IsEmpty() const;
  ~TStack()
  {
    delete [] pMem;
  }
};

template<class T>
TStack<T>::TStack(int _size)
{
	size = _size;
	top = -1;
	if ((size < 1) || (size > MaxStackSize))
		throw Stack_Exception::Invalid_Size;
	pMem = new T[size];
}

template<class T>

TStack<T>::TStack(const TStack<T>& s)
{
	size = s.size;
	top = s.top;
	pMem = new T[size];
	for (int i = 0; i <= top; i++)
	{
		pMem[i] = s.pMem[i];
	}
}

template<class T>
void TStack<T>::Push(T a)
{
	if (IsFull()) throw Stack_Exception::Stack_OverFlow;
	top++;
	pMem[top] = a;
}
template<class T>

T TStack<T>::Pop()
{
	if (IsEmpty()) throw Stack_Exception::Stack_Empty;
	return pMem[top--];
}
template<class T>

bool TStack<T>::IsFull() const
{
	return top >= size - 1;
}
template<class T>

bool TStack<T>::IsEmpty() const
{
	return top < 0;
}
#endif
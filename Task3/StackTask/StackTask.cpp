#include <iostream>
#include "Stack.cpp"
using namespace std;
int main()
{
	Stack<int> st1(8);
	Stack<int> st2(8);
	st1.Push(1);
	st1.Push(2);
	st1.Push(3);
	st2.Push(1);
	Stack<int> st3(st1,st2);
	while (!st3.thisstack.empty())
	{
		cout << st3.thisstack.top() << ' ';
		st3.Pop();
	}
}


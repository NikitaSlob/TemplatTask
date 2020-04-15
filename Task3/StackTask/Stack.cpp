#include "iostream"
#include "stack"
using namespace std;
#pragma once
template<typename t> class Stack
{
public:
	stack<t> thisstack;
	unsigned int length;
	Stack(unsigned int length)
	{
		this->length = length;
	}
	void Push(t a)
	{
		thisstack.push(a);
		if (thisstack.size() > this->length)
		{
			Pop();
			throw new exception("SetOverflow");
		}
	}
	void Pop()
	{
		thisstack.pop();

	}
	Stack(Stack<t> s1, Stack<t> s2)
	{
		this->length = s1.thisstack.size() + s2.thisstack.size();
		stack<t> st1 = s1.thisstack;
		stack<t> st2 = s2.thisstack;
		while (!st1.empty())
		{
			Push(st1.top());
			st1.pop();
		}
		while (!st2.empty())
		{
			this->thisstack.push(st2.top());
			st2.pop();
		}
	}
	~Stack() {}
};

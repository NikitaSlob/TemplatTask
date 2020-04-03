#pragma once
#include "set"
using namespace std;
template<typename t> class Set
{
private:
	set<t> thisset;
	unsigned int Length;
public:
	Set(unsigned int Length)
	{
		this->Length = Length;
	}
	void Push(t a)
	{
		thisset.insert(a);
		if (thisset.size() > this->Length)
		{
			thisset.erase(a);
			throw new exception("SetOverflow");
		}
	}
	void Pop(t a)
	{
		thisset.erase(a);
	}
	Set(Set s1, Set s2)
	{
		this->Length = s1.thisset.size() + s2.thisset.size();
		for(t index: s1.thisset)
		{
			this->thisset.insert(index);
		}
		for(t index : s2.thisset)
		{
			this->thisset.insert(index);
		}
	}
	~Set() {}

};


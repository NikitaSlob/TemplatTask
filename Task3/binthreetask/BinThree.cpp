#pragma once
#include "iostream"
#include "vector"
using namespace std;

template<typename t> class BinThree
{
private:
	struct point
	{
		t value;
		int parent = -1;
		int lchild = -1;
		int rchild = -1;
	};
	vector<point> three;
public:
	BinThree(t value)
	{
		point x;
		x.value = value;
		three.push_back(x);
	}
	void Push(t value)
	{
		point x;
		x.value = value;

		bool b = true;
		int i = 0;
		while (b)
		{
			if (x.value <= three[i].value)
			{
				if (three[i].lchild == -1)
				{
					three[i].lchild = three.size();
					x.parent = i;
					three.push_back(x);
					b = false;
				}
				else
					i = three[i].lchild;
			}
			else
			{
				if (three[i].rchild == -1)
				{
					three[i].rchild = three.size();
					x.parent = i;
					three.push_back(x);
					b = false;
				}
				else
					i = three[i].rchild;
			}
		}

	}
	void Pop(t value)
	{
		int i = this->Search(value);
		if (i != -1)
		{
			if (three[i].lchild == -1 && three[i].rchild == -1)
				three.erase(three.begin()+i);
			else
				if (three[i].lchild == -1)
				{
					int j = three[i].rchild;

					three[i].value = three[three[i].rchild].value;
					three[i].value = three[three[i].rchild].rchild;
					three[i].value = three[three[i].rchild].lchild;
					three[three[i].rchild].parent = i;
					three.erase(three.begin() + j);
				}
				else
					if (three[i].rchild == -1)
					{
						int j = three[i].lchild;
						three[i].value = three[three[i].lchild].value;
						three[i].value = three[three[i].lchild].rchild;
						three[i].value = three[three[i].lchild].lchild;
						three[three[i].lchild].parent = i;
						three.erase(three.begin() + j);
					}
					else
					{
						int j = three[i].rchild;
						three[i].value = three[three[i].rchild].value;
						three[i].value = three[three[i].rchild].rchild;
						int z = three[i].lchild;
						int z1 = three[i].lchild;
						three[i].value = three[three[i].rchild].lchild;
						three[three[i].rchild].parent = i;
						three[three[i].lchild].parent = i;
						three.erase(three.begin() + j);
						while (three[z].lchild != -1)
						{
							z = three[z].lchild;
						}
						three[z].lchild = z1;
						three[three[z].lchild].parent = z;
					}
		}
	}
	void Print()
	{
		for (int i = 0; i < three.size(); i++)
			cout << three[i].value << ' ';
		cout << endl;
	}
	int Search(t value)
	{
		int i = 0;
		bool b = true;
		int r = -1;
		while (b)
		{
			if (value < three[i].value)
			{
				if (three[i].value == value)
				{
					b = false;
					r = i;
				}
				else
					if (three[i].lchild == -1)
					{
						b = false;
					}
					else
						i = three[i].lchild;
			}
			else
			{
				if (three[i].value == value)
				{
					b = false;
					r = i;
				}
				else
					if (three[i].rchild == -1)
					{
						b = false;
					}
					else
						i = three[i].rchild;
			}
			
		}
		return r;
	}
	void Printl()
	{
		for (int i = 0; i < three.size(); i++)
			if(three[i].lchild==-1 && three[i].rchild==-1)
			cout << three[i].value << ' ';
		cout << endl;
	}
	~BinThree()
	{	}
};
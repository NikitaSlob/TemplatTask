
#include <iostream>
#include <vector>
#include "BinThree.cpp"
using namespace std;
int main()
{
	BinThree<int> th(3);
	th.Push(2);
	th.Push(1);
	th.Push(5);
	th.Push(4);
	th.Push(6);
	th.Push(2);
	th.Print();
	th.Printl();
	th.Pop(3);
	th.Print();
}



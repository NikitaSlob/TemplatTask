#include <iostream>
#include "Set.cpp"
using namespace std;
int main()
{
	Set<string> s1(10);
	s1.Push("1");
	s1.Push("2");
	s1.Push("3");
	Set<string> s2(1);
	s2.Push("1");
	Set<string> s(s1, s2);
	s1.Pop("1");
	s1.Pop("0");
}

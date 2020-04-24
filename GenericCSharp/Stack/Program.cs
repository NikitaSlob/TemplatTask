using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack
{
    class Program
    {
        static void Main(string[] args)
        {
            StackCl<int> st1=new StackCl<int>(8);
            StackCl<int> st2=new StackCl<int>(8);
            st1.Push(1);
            st1.Push(2);
            st1.Push(3);
            st2.Push(1);
            StackCl<int> st3=new StackCl<int>(st1, st2);
            while (st3.thisstack.Count()!=0)
            {
                Console.WriteLine(st3.thisstack.First().ToString());
                st3.Pop();
            }
            StackCl<string> st4 = new StackCl<string>(8);
            st4.Push("1");
            st4.Pop();
            st4.Pop();
        }
    }
}

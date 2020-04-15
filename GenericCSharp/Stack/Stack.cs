using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Stack
{
    class StackCl<T> 
    {
        public Stack<T> thisstack;
        int length;
        public StackCl(int length)
        {
            if (length > 0)
            {
                this.length = length;
                thisstack = new Stack<T>();
            }
            else
                throw new ArgumentException();
        }
        public void Push(T a)
        {
            thisstack.Push(a);
            if (thisstack.Count() > this.length)
            {
                Pop();
                throw new IndexOutOfRangeException("StackOverflow");
            }
        }
        public void Pop()
        {
            thisstack.Pop();

        }
        public StackCl(StackCl<T> s1, StackCl<T> s2)
        {
            this.length = s1.thisstack.Count() + s2.thisstack.Count();
            thisstack = new Stack<T>();
            Stack<T> st1 = s1.thisstack;
            Stack<T> st2 = s2.thisstack;
            while (st1.Count() != 0)
            {
                Push(st1.First());
                st1.Pop();
            }
            while (st2.Count() != 0)
            {
                Push(st2.First());
                st2.Pop();
            }
        }
        ~StackCl() { }
    }
}

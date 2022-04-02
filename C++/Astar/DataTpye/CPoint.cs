using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace console_Test
{
    // 구조체는  반드시 내부 변수들이 값을 포함해야함
    // 클래스는 기능에 초점이 있기 때문에 비어있을 수 있음
    public class CPoint
    {
        public int X;
        public int Y;

        void init()
        {
            X = -1;
            Y = -1;
        }

        CPoint SetPoint(int x, int y)
        {
            X = x;
            Y = y;

            return this; 
        }

        public static bool operator == (in CPoint master, in CPoint other)
        {
            bool xEqual = master.X == other.X;
            bool yEqual = master.Y == other.Y;

            return xEqual && yEqual;
        }

        public override bool Equals(Object other) 
         {  
             return true;  
         }  

        public static bool operator !=(in CPoint master, in CPoint other)
        {
            bool xEqual = master.X != other.X;
            bool yEqual = master.Y != other.Y;

            return xEqual && yEqual;           
        }
    }  
}

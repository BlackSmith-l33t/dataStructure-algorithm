using System;
using System.Collections.Generic;

namespace console_Test
{
    class Program
    {
        static void Main(string[] args)
        {
			// 0 : 못 가는 지역
			// 1 : 갈 수 있는 지역
			bool[,] map = new bool[Constans.MAP_SIZE, Constans.MAP_SIZE]
			{
				{ true, true, true, true, true, true, true },
				{ true, false, false, false, false, false, true },
				{ true, false, true, true, true, false, true },
				{ true, false, false, true, true, false, true },
				{ true, false, true, true, true, false, true },
				{ true, false, true, true, true, false, true },
				{ true, true, true, true, true, false, true }
			};

			AStart finderAStart = new AStart();
			LinkedList<Point> path = finderAStart.astar(map, new Point(2, 2), new Point(6, 6), MODE.None8);

			if (path.Count == 0)
				Console.WriteLine("경로를 못찾았습니다.");
			else
				finderAStart.PrintPathMap(map, path);
		}
    }
}

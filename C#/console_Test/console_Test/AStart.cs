using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

static class Constans
{
	public const int MAP_SIZE = 7;  // 맵 크기 설정
	public const int INF = 99999;   // 무한값 설정
}

namespace console_Test
{
	public enum MODE                                                                                                                  
	{ 
		Normal4, 
		None8,
		Half8,
		Both8,

		max			
	};

	class AStart
    {		
		//  			    상   하  좌  우  우상 좌상 좌하 우하
		public readonly int[] directionX = { 0,  0, -1,  1,  1,  -1,  -1,   1 };
		public readonly int[] directionY = { 1, -1,  0,  0,  1,   1,  -1,  -1 };
		
		int GetH(in Point start, in Point end)
        {
			int xSize = Math.Abs(start.X - end.X);       // 가로로 가야 하는 횟수
			int ySize = Math.Abs(start.Y - end.Y);       // 세로로 가야 하는 횟수

			int straight;       // 직선으로 가야 하는 횟수
			int diagonal;       // 대각선으로 가야 하는 횟수

			if (xSize > ySize)
				diagonal = ySize;
			else
				diagonal = xSize;

			int large;
			if (xSize > ySize)
				large = xSize;
			else
				large = ySize;

			straight = large - diagonal;

			return 10 * straight + 14 * diagonal;			
        }

		CNode FindMinFNode(LinkedList<CNode> list)
		{
			CNode minFNode = list.Last();
			int minF = Constans.INF;
			int minH = Constans.INF;
			foreach (CNode dummyNode in list)
			{
				if (true == dummyNode.active &&					     // 활성화 됐으면서
					(dummyNode.f < minF ||							 // f가 가장 낮은 정점을 찾자
					dummyNode.f == minF && dummyNode.h < minH))      // f 가 똑같다면, 그나마 h가 작은 애로
				{
					minFNode = dummyNode;
					minF = dummyNode.f;
					minH = dummyNode.h;
				}
			}

			return minFNode;
		}

		CNode FindNodeByPoint(LinkedList<CNode> list, Point point)
		{
			CNode resultIter = list.Last();
			foreach (CNode node in list)
			{
				if (node.point == point)
				{
					resultIter = node;
				}
			}
			return resultIter;
		}

		public LinkedList<Point> astar(in bool[,] map, in Point start, in Point end, MODE mode)
		{
			LinkedList<CNode> m_list = new();  // new List<CNode> { };

			CNode startNode = new CNode(true, null, start, 0, GetH(start, end));
			m_list.AddFirst(startNode);

			while (true)
			{
				// 0. 다음으로 탐색할 정점을 list에서 찾아준다.
				// 다음으로 탐색할 정점 == f가 가장 낮은 정점.

				CNode minFNode = FindMinFNode(m_list);

				// 1. 도착지에 도착했을 때 
				// 경로를 return;
				if (minFNode != m_list.Last() && minFNode.point == end)
				{
					CNode endNode = minFNode;
					CNode pPathNode = endNode;

					LinkedList<Point> path = new();

					while (pPathNode != null)
					{
						path.AddFirst(pPathNode.point);
						pPathNode = pPathNode.connect;
					}
					return path;
				}

				// 2. 더 이상 탐색할 수 없을 때, lsit에 더이상 탐색할 정점이 없음.
				// 경로를 없이 return;
				if (minFNode == m_list.Last())
				{
					LinkedList<Point> path = new();
					return path;
				}

				// 3. 탐색할 정점을 탐색
				// 3-1 상하좌우 정점들의 f, g, h 를 계산해준다.
				for (int i = 0; i < 8; i++)
				{
					int x = minFNode.point.X + directionX[i];
					int y = minFNode.point.Y + directionY[i];

					CNode node = FindNodeByPoint(m_list, new Point(x, y));

					// 탐색하면 안되는 경우
					// 탐색 안하게 해줌
					// 맵을 벗어 났을 때
					if (x < 0 || x >= Constans.MAP_SIZE || y < 0 || y >= Constans.MAP_SIZE)
						continue;
					// 벽일 때
					else if (false == map[y, x])
						continue;
					// 비활성화 된 정점일 때
					else if (m_list.Last() != node && false == node.active)
						continue;

					// Mode가 4방향일 때 대각선은 못 탐색
					if (mode == MODE.Normal4 && i >= 4)
						continue;

					Point wall1 = new Point(x, minFNode.point.Y);
					Point wall2 = new Point(minFNode.point.X, y);
					// Mode가 None일 때 대각선
					if (mode == MODE.None8 && (false == map[wall1.Y, wall1.X] || false == map[wall2.Y, wall2.X]))
						continue;
					// Mode가 Half일 때 대각선
					if (mode == MODE.Half8 && (false == map[wall1.Y, wall1.X] && false == map[wall2.Y, wall2.X]))
						continue;

					// 새로운 f, g, h
					int newG;
					if (minFNode.point.X != x && minFNode.point.Y != y)
						newG = minFNode.g + 14;
					else
						newG = minFNode.g + 10;                 // 나를 탐색한 정점이 갖는 g에서 10 더 더함
					int newH = GetH(new Point(x, y), end);      // 내 좌표부터 도착지 까지 H 함수로 짰으므로
					int newF = newG + newH;                     // f = g + h;

					// 한번도 안 구해본 정점일때
					// 그냥 구해 줘야 되고
					// 리스트에 그 정점도 추가해 줘야됨
					if (m_list.Last() == node)
					{
						m_list.AddLast(new CNode(true, minFNode, new Point(x, y), newG, newH));
					}
					// 이미 있던 정점 일때
					// f가 더 작을때만 바꿔줌
					else if (node.f > newF)
					{
						node.g = newG;
						node.h = newH;
						node.f = newF;
						node.connect = minFNode;
					}
				}

				// 3-2 탐색하는 정점을 비활성화 시켜주면 된다.
				minFNode.active = false;
			}
		}

		public void PrintMap(in bool[,] graph)
		{
			for (int i = 0; i < Constans.MAP_SIZE; i++)
			{
				for (int j = 0; j < Constans.MAP_SIZE; j++)
				{
					Console.Write(graph[i, j] + " ");
				}
				Console.WriteLine();
			}
		}

		public void PrintPathMap(in bool[,] graph, LinkedList<Point> path)
		{
			char[,] pathMap = new char[Constans.MAP_SIZE, Constans.MAP_SIZE];
			for (int i = 0; i < Constans.MAP_SIZE; i++)
			{
				for (int j = 0; j < Constans.MAP_SIZE; j++)
				{
					if (graph[i, j] == false)
						pathMap[i, j] = '#';
					else if (graph[i, j] == true)
						pathMap[i, j] = ' ';
				}
			}	

			foreach (Point dummy in path)
			{
				pathMap[dummy.Y, dummy.X] = '*';
			}
			Point start = path.First();
			Point end = path.Last();
			pathMap[start.Y, start.X] = 'S';
			pathMap[end.Y, end.X] = 'E';

			for (int i = 0; i < Constans.MAP_SIZE + 2; i++)
				Console.Write("#");
			Console.WriteLine();
			for (int i = 0; i < Constans.MAP_SIZE; i++)
			{
				Console.Write("#");
				for (int j = 0; j < Constans.MAP_SIZE; j++)
				{
					Console.Write(pathMap[i, j]);
				}
				Console.WriteLine("#");
			}
			for (int i = 0; i < Constans.MAP_SIZE + 2; i++)
				Console.Write("#");
			Console.WriteLine();
		}
	}
}

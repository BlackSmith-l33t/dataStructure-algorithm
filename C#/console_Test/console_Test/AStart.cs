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

//						   상,  하, 좌, 우 우상 좌상 좌하 우하

//			     상하좌우  벽없을 한쪽만 두쪽다


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
		int[] directionX = { 0,  0, -1,  1,  1,  -1,  -1,   1 };
		int[] directionY = { 1, -1,  0,  0,  1,   1,  -1,  -1 };
		
		int GetH(in CPoint start, in CPoint end)
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

		CNode FindMinFNode(List<CNode> list)
		{
			CNode minFNode = list[list.Count - 1];
			int minF = Constans.INF;
			int minH = Constans.INF;
			foreach (CNode dummyNode in list)
			{
				if (true == dummyNode.active &&				  // 활성화 됐으면서
					(dummyNode.f < minF ||					  // f가 가장 낮은 정점을 찾자
					dummyNode.f == minF && dummyNode.h < minH))     // f 가 똑같다면, 그나마 h가 작은 애로
				{
					minFNode = dummyNode;
					minF = dummyNode.f;
					minH = dummyNode.h;
				}
			}

			return minFNode;
		}

		CNode findNodeByPoint(List<CNode> list, CPoint point)
		{
			CNode resultIter = list[list.Count - 1];
			foreach (CNode node in list)
			{
				if (node.point == point)
				{
					resultIter = node;
				}
			}
			return resultIter;
		}

		List<CPoint> astar(in bool[][] map, in CPoint start, in CPoint end, MODE mode)
        { 
			List<CNode> m_list = new();  // new List<CNode> { };

			CNode startNode = new CNode(true, null, start, 0, GetH(start, end));
			m_list.Add(startNode);

			while (true)
            {
				// 0. 다음으로 탐색할 정점을 list에서 찾아준다.
				// 다음으로 탐색할 정점 == f가 가장 낮은 정점.

				CNode minFNode = FindMinFNode(m_list);

				// 1. 도착지에 도착했을 때 
				// 경로를 return;
				if (minFNode != m_list[m_list.Count - 1] && minFNode.point == end)
                {
					 CNode endNode = minFNode;
					 CNode pPathNode = endNode;

					List<CPoint> path = new();

					while (pPathNode != null)
                    {
						path.Insert(0, pPathNode.point);
						pPathNode = pPathNode.connect;
                    }
					return path;
                }

				// 2. 더 이상 탐색할 수 없을 때, lsit에 더이상 탐색할 정점이 없음.
				// 경로를 없이 return;
				if (minFNode == m_list[m_list.Count	- 1])
                {
					List<CPoint> path = new();
					return path;
                }
            }

			{
				List<CPoint> path = new List<CPoint> { };
				return path;
			}
		}



	}
}

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
			CNode minFIter = list[list.Count - 1];
			int minF = Constans.INF;
			int minH = Constans.INF;
			foreach (CNode node in list)
			{
				if (true == node.active &&				  // 활성화 됐으면서
					(node.f < minF ||					  // f가 가장 낮은 정점을 찾자
					node.f == minF && node.h < minH))     // f 가 똑같다면, 그나마 h가 작은 애로
				{
					minFIter = node;
					minF = node.f;
					minH = node.h;
				}
			}

			return minFIter;
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


			List<CPoint> path = new List<CPoint> { };
			return path;

		}



	}
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace console_Test
{
    public class CNode
    {
		public bool active;      // 활성화 여부
		public CNode connect;    // 이전 정점의 포인터 변수
		public Point point;     // 현재 좌표
		public int f;            // 예상 최단거리 (g + h)
		public int g;            // 지금까지 온 거리
		public int h;            // 예상 거리 (장애물 X)
		
		CNode()
        {
			active = false;
			f = Constans.INF;
			g = Constans.INF;
			h = Constans.INF;
		}

		public CNode(bool active, CNode connect, Point point, int g, int h)
        {
			this.active = active;
			this.connect = connect;
			this.point = point;
			this.g = g;
			this.h = h;
			this.f = g + h;
		}
	}
}

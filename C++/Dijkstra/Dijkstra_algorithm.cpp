#include <iostream>

#define GRAPH_SIZE  9
#define INF         99999

using namespace std;

int graph1[GRAPH_SIZE][GRAPH_SIZE] =
{  // A   B		C	 D	  E	   F	G	 H	  I
   // 1	  2		3	 4	  5    6    7    8    9
	{  0, INF,   2, INF, INF, INF, INF, INF,   9}, //A 1
	{INF,   0,   7, INF, INF, INF,   2, INF, INF}, //B 2
	{  2,   7,   0, INF,  10,   8, INF, INF, INF}, //C 3
	{INF, INF, INF,   0, INF, INF, INF, INF,   3}, //D 4
	{INF, INF,  10, INF,   0, INF, INF,   6, INF}, //E 5
	{INF, INF,   8, INF, INF,   0, INF, INF, INF}, //F 6
	{INF,   2, INF, INF, INF, INF,   0, INF,  11}, //G 7
	{INF, INF, INF, INF,   6, INF, INF,   0, INF}, //H 8
	{  9, INF, INF,   3, INF, INF, INF,  11,   0}  //I 9
};

/* 그래프1 최단 거리 결과
0, 9, 2, 12, 12, 10, 11, 18, 9,
9, 0, 7, 16, 17, 15, 2, 23, 13,
2, 7, 0, 14, 10, 8, 9, 16, 11,
12, 21, 14, 0, 20, 22, 23, 14, 3,
12, 17, 10, 24, 0, 18, 19, 6, 21,
10, 15, 8, 22, 18, 0, 17, 24, 19,
11, 2, 9, 14, 19, 17, 0, 22, 11,
18, 23, 16, 30, 6, 24, 25, 0, 27,
9, 18, 11, 3, 17, 19, 20, 11, 0,
*/

void dijkstra(int start, int distance[GRAPH_SIZE])
{
	// 1. 출발 노드를 설정
	// 2. 출발 노드를 기준으로 각 노드의 최소 거리값을 저장
	// 3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드를 선택
	// 4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용 갱신
	// 5. 위 과정에서 3번 ~ 4번을 반복

	bool visited[GRAPH_SIZE] = { false };
	visited[start] = true;	

	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		distance[i] = graph1[start][i];	
	}		
	
	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		int min_value = INF;
		int min_index = 0;

		for (int j = 0; j < GRAPH_SIZE; j++)
		{
			if (!visited[j] && (distance[j] < min_value))
			{
				min_value = distance[j];
				min_index = j;
			}			
		}

		visited[min_index] = true;

		// 가장 가까운 정점부터 탐색
		for (int k = 0; k < GRAPH_SIZE; k++)
		{
			if (!visited[k] && distance[k] > graph1[min_index][k] + distance[min_index])
			{
				distance[k] = graph1[min_index][k] + distance[min_index];
			}
		}
	}	
}

int main()
{
	int distance[GRAPH_SIZE];

	for (int j = 0; j < GRAPH_SIZE; j++)
	{
		dijkstra(j, distance);
		for (int i = 0; i < GRAPH_SIZE; i++)
		{
			cout << distance[i] << ", ";
		}
		cout << endl;
	}

}
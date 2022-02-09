#include <iostream>
#include <stack>
#include <queue>

#define MAX_SIZE        8

using namespace std;

bool graph1[MAX_SIZE][MAX_SIZE] = {
        {0, 1, 1, 0, 0, 0, 0, 1}, // 1
        {1, 0, 0, 0, 0, 0, 1, 0}, // 2
        {1, 0, 0, 1, 1, 0, 0, 0}, // 3
        {0, 0, 1, 0, 1, 0, 0, 0}, // 4
        {0, 0, 1, 1, 0, 0, 0, 0}, // 5 
        {0, 0, 0, 0, 0, 0, 1, 0}, // 6
        {0, 1, 0, 0, 0, 1, 0, 1}, // 7
        {1, 0, 0, 0, 0, 0, 1, 0}  // 8
};

bool graph2[MAX_SIZE][MAX_SIZE] = {
        {0, 1, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 1, 0}
};

bool graph3[MAX_SIZE][MAX_SIZE] = {
        {0, 1, 1, 0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0, 1},
        {0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 0}
};

bool dfs_visited[MAX_SIZE] = { false };
void dfs(int start)
{
    stack<int> dfs_stack;  
    dfs_stack.push(start);
    cout << dfs_stack.top() + 1 << ", ";
    int index = 0;  

    while (!dfs_stack.empty())
    {
        if (graph1[start][index] && !dfs_visited[index])
        {
            dfs_stack.push(index);    
            dfs_visited[start] = true;
            dfs(index);   
            dfs_stack.pop();
        }         
        ++index;

        if (index == MAX_SIZE)
        {
            dfs_visited[start] = true;
            break;
        }
    }
}

bool bfs_visited[MAX_SIZE] = { false };
void bfs(int start)
{
    queue<int> bfs_Queue;

    bfs_Queue.push(start);
    bfs_visited[start] = true;

    while (!bfs_Queue.empty())
    {
        cout << bfs_Queue.front() + 1 << ", ";
        int index = bfs_Queue.front();
        bfs_Queue.pop();      

        for (int i = 0; i < MAX_SIZE; i++)
        {
            if ((bfs_visited[i] == false) && (true == graph1[index][i]))
            {
                bfs_Queue.push(i);
                bfs_visited[i] = true;
            }
        }               
    }
}

int main()
{
    cout << "dfs : ";
    dfs(0);
    cout << endl;

    cout << "bfs : ";
    bfs(0);
    cout << endl;
}
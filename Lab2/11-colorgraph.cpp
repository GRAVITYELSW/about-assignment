//图的m着色问题
#include <iostream>
using namespace std;

int n, r, m, count = 0;
int graph[200][200], color[20];

bool same(int i)
{
    for(int j = 0; j < n; j++)
    {
        if(graph[i][j] == 1 && color[i] == color[j])
            return false;
    }
    return true;
}

void dfs(int i)
{
    if(i >= n)
        count++;
    else
    {
        for(int j = 1; j <= m; j++)
        {
            color[i] = j;
            if(same(i))
                dfs(i + 1);
            color[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> r >> m;
    for(int i = 0; i < r; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1, graph[b][a] = 1;
    }
    dfs(0);
    cout << count << endl;
    return 0;
}
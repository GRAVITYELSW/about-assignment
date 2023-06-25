#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <functional>
#include <map>
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 1010;

struct Node
{
    int v;
    Node *next=NULL;
};

Node *g[105];

void Link(int u,int v)
{
    Node *p = new Node;
    p->v = v;
    p->next = g[u];
    g[u] = p;
}

void bfs(int now,int goal,bool& flag)
{
    queue<int> q;
    q.push(now);
    Node*p;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (p=g[u];p!=NULL;p=p->next)
        {
            int v = g[u]->v;
            q.push(v);
            if (v == goal)
            {
                flag = true;
                return;
            }
        }
    }
}

int main()
{
    //freopen("test2.txt","r",stdin);
    int n,m,x;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> x;
    for (int i=0;i<=n;i++)
        g[i] = NULL;

    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u >> v;
        Link(u,v);
    }

    int vi,vj;
    cin >> vi >> vj;

    bool flag = false;
    bfs(vi,vj,flag);
    if (flag) cout <<"yes";
    else cout << "no";
    return 0;
}

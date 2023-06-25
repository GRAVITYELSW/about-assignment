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

void dfs(int now,int goal,bool& flag)
{
    if (now == goal) flag = true;
    if (flag) return;
    Node *p = g[now];
    while (p!=NULL)
    {
      dfs(p->v,goal,flag);
      p = p->next;
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
    dfs(vi,vj,flag);
    if (flag) cout <<"yes";
    else cout << "no";
    return 0;
}

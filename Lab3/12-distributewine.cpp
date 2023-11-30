//分酒问题
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> b;     
int used[10000], step[10000], path[10000]; 
int result[100][3];   
int cap[3]; 
queue<vector<int>> q; 

/**
 * 如果当前瓶子内的酒大于交换的瓶子的剩余体积，则交换的瓶子装满，当前瓶子内酒的体积减少
 * 如果当前瓶子内的酒小于交换的瓶子的剩余体积，则酒全部装入交换的瓶子，当前瓶子为空
*/
vector<int> nextstage(vector<int> now, int i, int j)
{
    vector<int> next = now; 
    if(next[i] > (cap[j] - next[j]))
    {
        next[i] -= (cap[j] - next[j]);
        next[j] = cap[j];
    }
    else
    {
        next[j] += next[i];
        next[i] = 0;
    }
    return next;
}

/**
 * 对于当前瓶子，如果不为空，则遍历剩下两个瓶子进行酒的交换（利用(i + j) % 3）
 * i为当前瓶子，j为与之相交换的瓶子
 * 
 * 注释掉的代码为输出每次交换后三个瓶子体积的状态函数
*/
void bfs()
{  
    while(!q.empty()){
        vector<int> now = q.front();
        q.pop();
        for(int i = 0; i < 3; i++)
        {
            if(now[i] != 0)
            {
               for(int j = 1; j < 3; j++)
               {
                    vector<int> next = nextstage(now, i, (i + j) % 3);
                    if(!used[next[0] * 100 + next[1] * 10 + next[2]])
                    {
                        step[next[0] * 100 + next[1] * 10 + next[2]] = step[now[0] * 100 + now[1] * 10 + now[2]] + 1;
                        //path[next[0] * 100 + next[1] * 10 + next[2]] = now[0] * 100 + now[1] * 10 + now[2];
                        if(next[0] == cap[0] / 2 && next[1] == cap[0] / 2)
                            return;

                        q.push(next);
                        used[next[0] * 100 + next[1] * 10 + next[2]] = 1;
                    }
               }
            }
        }
    }
    return ;
}

/*
void dispath()
{
    int count = step[(cap[0] / 2) * 110];
    result[count][2] = 0, result[count][1] = cap[0] / 2, result[count][0] = cap[0] / 2; 
    int wine = path[(cap[0] / 2) * 110];
    for(int i = count - 1; i > 0; i--)
    {
        result[i][2] = wine % 10, result[i][1] = (wine / 10) % 10, result[i][0] = wine / 100; 
        wine = path[wine];
    }
    for(int i = 1; i <= count; i++)
        cout << "第" << i << "次:" << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
}
*/

int main()
{
    cin >> cap[0] >> cap[1] >> cap[2];
    used[cap[0] * 100] = 1, path[cap[0] * 100] = 0;
    b.push_back(cap[0]), b.push_back(0), b.push_back(0);
    q.push(b);
    bfs();
    cout << step[(cap[0] / 2) * 110];
    //dispath();
    return 0;
}

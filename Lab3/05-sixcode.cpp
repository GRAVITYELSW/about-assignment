//六数码问题
#include<iostream>
#include<queue>
using namespace std;

typedef struct node
{
	int table[6];
	int num;
} node;

node start;
queue<node> q;
int used[654322];

int setnum(node n)
{
	n.num = 0;
	for(int i = 0; i < 6; i++)
	{
		n.num *= 10;
		n.num += n.table[i];
	}
	return n.num;
}

bool istarget(node n)
{
	if(n.num == 123456) 
        return true;
	else 
        return false;
}

node operate(node now,int i)
{
	node next;
	if(i == 0)
	{
		next.table[0] = now.table[3];
		next.table[1] = now.table[0];
		next.table[2] = now.table[2];
		next.table[3] = now.table[4];
		next.table[4] = now.table[1];
		next.table[5] = now.table[5];
	}
	if(i==1)
	{
	    next.table[0] = now.table[0];
		next.table[1] = now.table[4];
		next.table[2] = now.table[1];
		next.table[3] = now.table[3];
		next.table[4] = now.table[5];
		next.table[5] = now.table[2];	
	}
	next.num = setnum(next);
	return next;
}

void init()
{
	for(int i = 123456; i < 654322; i++)
	{
		used[i] = 0;
	}
	while(!q.empty())
	{
		q.pop();
	}
	q.push(start);
	used[start.num] = 1;
}

bool bfs()
{
	node now, next;
	while(!q.empty())
	{
		now = q.front();
		q.pop();
		for(int i = 0; i < 2; i++)
		{
			next = operate(now,i);
			if(!used[next.num])
			{
				used[next.num]=1;
				if(istarget(next)) 
                    return true;
				else 
                    q.push(next);
			}
		}
	}
	return false;
}

int main()
{
	while(cin >> (start.table[0]))
	{
		for(int i = 1; i < 6; i++)
		{
			cin >> start.table[i];
		}
		start.num = setnum(start);
		init();
		if(bfs()) 
            cout<<"Yes"<<endl;
		else 
            cout<<"No"<<endl;
	}
	return 0;
}
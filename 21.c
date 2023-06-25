#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <list>
#include <set>
#include <queue>
#include <functional>
#include <map>
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 10010;

char stack1[maxn];
int top1 = 0;

bool judge(char a, char b)
{
	if ((a == '*' && (b == '+' || b == '-')) || (a == '/' && (b == '+' || b == '-')))
		return true;
	return false;
}

int main()
{
	//freopen("test2.txt","r",stdin);
	//freopen("w.txt", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		switch (s[i])
		{
		case '(':stack1[++top1] = s[i]; break;
		case ')':
		{
			while (stack1[top1] != '(')
			{
				cout << stack1[top1];
				top1--;
			}
			top1--;
			break;
		}
		default:
		{
			if (s[i] >= 'a' && s[i] <= 'z') cout << s[i];
			else
			{
				while (1)
				{
					if (judge(s[i], stack1[top1]) || stack1[top1] == 0)
					{
						stack1[++top1] = s[i];
						break;
					}
					else
						if (stack1[top1] == '+' || stack1[top1] == '-' || stack1[top1] == '*' || stack1[top1] == '/')
						{
							cout << stack1[top1];
							top1--;
						}
						else break;
				}
			}
		}
		}
	}
	while (top1)
	{
		cout << stack1[top1];
		top1--;
	}
	return 0;
}

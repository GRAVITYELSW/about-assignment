#include <iostream>
#include <stack>
#include <cstring>
#include <vector>
using namespace std;
#define N 100005

char a[N], b[N];
stack<char> st;
vector<char> op;
int p = 1;
int q = 1;
int len = 0;

/**
 * dfs深搜进行字母转换
 * 
 * 每一个字符都经历入栈和出栈两步，所以当n > 2 * len时输出栈内元素
 * 
 * 当p < len时，将第一个字符串中剩下的元素全部入栈
 * 全部入栈后，将栈顶元素与交换后的字符串的第一个字符进行比较，如果不对应，则栈顶出栈，比较下一个，直到找到相同字符
 * 找到相同字符后再次将剩余字符入栈，重复上述过程直到输出
 * 
 * 最后将栈和向量复原，为下一次做准备
*/
void dfs(int n)
{
    if(n > 2 * len)
    {
        for(int i = 0; i < op.size(); i++)
        {
            if(i != op.size() - 1)
                cout << op[i] << " ";
            else 
                cout << op[i];
        }
        cout << endl;
        return;
    }
    if(p <= len)
    {
        op.push_back('i');
        st.push(a[p]);
        p++;
        dfs(n+1);
        op.pop_back();
        st.pop();
        p--;
    }
    if(st.size() && st.top() == b[q])
    {
        op.push_back('o');
        char tmp = st.top();
        st.pop();
        q++;
        dfs(n+1);
        q--;
        st.push(tmp);
        op.pop_back();
    }
}

int main()
{
    while(scanf("%s%s", a+1, b+1) != EOF)   //从首地址+1开始读入
    {
        int len1 = strlen(a+1);
        int len2 = strlen(b+1);
        if(len1 != len2)
        {
            cout << "[" << endl << "]" << endl;
            continue;
        }

        len = len1;
        cout << "[" << endl;
        dfs(1);
        cout << "]" << endl;
    }
    return 0;   
}
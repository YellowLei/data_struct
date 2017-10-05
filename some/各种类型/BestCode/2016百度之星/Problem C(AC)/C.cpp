#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

const int maxnode = 3000000;
const int sigma_size = 27;

struct Node
{
    int x,y;
    Node(int a,int b):x(a),y(b){}
    Node() {}
};

struct Trie
{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int sz;
    Trie() {sz = 1; memset(ch[0], 0, sizeof(ch[0]));}
    int idx(char c)
	{
		return c - 'a';
	}

    void Insert(char *s)
    {
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if(!ch[u][c])
            {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 1;
                ch[u][c] = sz++;
                u = ch[u][c];
            }
            else
            {
                u = ch[u][c];
                val[u]++;
            }
        }
    }

    void Search(char *s)
    {
        int u = 0,n = strlen(s);
        for(int i = 0; i < n; i++)
        {
            int c = idx(s[i]);
            if(!ch[u][c])
            {
                printf("No\n");
                return;
            }
            else u = ch[u][c];
        }
        printf("Yes\n");
        return ;
    }

    void Delete(char *s)
    {
        stack <Node> S;
        while(!S.empty()) S.pop();
        int u = 0,n = strlen(s),f,c;
        for(int i = 0; i < n; i++)
        {
            c = idx(s[i]);
            S.push(Node(u,c));
            if(!ch[u][c])
                return;
            else
            {
                f = u;
                u = ch[u][c];
            }
        }
        ch[f][c] = 0;
        if(val[f] - val[u] == 0)
        {
            S.pop();
            while(!S.empty())
            {
                Node node = S.top();
                S.pop();
                int temp = ch[node.x][node.y];
                if(val[temp] - val[u]) break;
                else ch[node.x][node.y] = 0;
            }
        }
    }
};


Trie t;
int main()
{
    int n;
    scanf("%d",&n);
    char op[7],str[35];
    while(n--)
    {
        scanf("%s%s",op,str);
        if(op[0] == 'i')
            t.Insert(str);
        else if(op[0] == 's')
            t.Search(str);
        else if(op[0] == 'd')
            t.Delete(str);
    }
    return 0;
}

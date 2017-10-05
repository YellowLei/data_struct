//博客上的代码   没看懂
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<queue>
using namespace std;
int ans[1111][5];
char str[1111111];
#define cc 130
int id,visited[1111],a[1111];
struct node
{
	int n;
	struct node *next[cc];
	struct node *fail;
	void init()
	{
		int i;
		for(i=0;i<cc;i++)
			next[i]=NULL;
		n=0;
		fail=NULL;
	}
}*root;
void insert()
{
	int len,k;
	node *tmp=root;
	len=strlen(str);
	for(k=0;k<len;k++)
	{
		int pos=str[k]-31;
		if(tmp->next[pos]==NULL)
		{
			tmp->next[pos]=new node;
			tmp->next[pos]->init();
			tmp=tmp->next[pos];
		}
		else tmp=tmp->next[pos];
	}
	tmp->n=id;
}

void getfail()
{
	int i;
	node *tmp,*temp,*son;
	queue<struct node *>que;
	que.push(root);
	tmp=root;
	while(!que.empty())
	{
		temp=que.front();
		que.pop();
		for(i=0;i<cc;i++)
		{
			son=temp->next[i];
			if(son!=NULL)
			{
				if(temp==root)
				{
					son->fail=root;
				}
				else
				{
					tmp=temp->fail;
					while(tmp)
					{
						if(tmp->next[i]!=NULL)
						{
							son->fail=tmp->next[i];///
							break;
						}
							tmp=tmp->fail;
					}
					if(tmp==NULL) son->fail=root;
				}
				que.push(son);
			}
		}
		 }
}

void query()
{
	int len,i,cnt=0,pos;
	len=strlen(str);
	node *tmp,*temp;
	tmp=root;
	for(i=0;i<len;i++)
	{
		pos=str[i]-31;
		while(!tmp->next[pos]&&tmp!=root)
			tmp=tmp->fail;
		tmp=tmp->next[pos];
		if(!tmp)
			tmp=root;
		temp=tmp;
		while(temp!=root)
		{
			if(temp->n>=1&&!visited[temp->n])
			{
				ans[id][cnt++]=temp->n;
				visited[temp->n]=1;
			}
			temp=temp->fail;
		}
	}
}
int main()
{
	int n,m,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		root= new node;
		root->fail=NULL;
		root->init();
		getchar();
		for(i=1;i<=n;i++)
		{
			gets(str);
			id=i;
			insert();
		}
		getfail();

		scanf("%d",&m);
		getchar();
		memset(ans,0,sizeof(ans));

		for(i=1;i<=m;i++)
		{
			memset(visited,0,sizeof(visited));
			id=i;
			gets(str);
			query();
		}
		int cnt=0;
		for(i=1;i<=m;i++)
		{
			if(ans[i][0]>=1)
			{
				cnt++;
				printf("web %d:",i);
				int a[1111];
				memset(a,0,sizeof(a));
				for(j=0;ans[i][j]>=1;j++)
				{
					a[ans[i][j]]=1;
				}
				int k;
				for(k=1;k<1100;k++)
				{
					if(a[k])
					 printf(" %d",k);
				}
				printf("\n");
			}
		}
		printf("total: %d\n",cnt);
	}
	return 0;

}

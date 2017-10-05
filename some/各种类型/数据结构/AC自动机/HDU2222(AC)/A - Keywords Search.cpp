#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int Max=26;
struct AC_Automata
{
	//结点数据结构
	struct node
	{
		node *next[Max];
		node *fail;    	 //失配指针
		int ncount;		 //字符串个数
		//构造
		node()
		{
			for(int i=0;i<Max;++i)
				next[i]=NULL;
			ncount=0;
			fail=NULL;
		}
	};

	node *root;		//根结点
	//构造函数
	AC_Automata()
	{
		 root=new node();
	}

	//插入单词到trie中
//1.首先我们需要建立一棵Trie。但是这棵Trie不是普通的Trie，而是带有一些特殊的性质。
	void insertTrie(char *s)
	{
		node *tmp=root;
		for(int i=0;s[i];++i)
		{
			int id=s[i]-'a';
			if(tmp->next[id]==NULL)
			{
				tmp->next[id]=new node();
			}
			tmp=tmp->next[id];
		}
		tmp->ncount++;
	}

	//创建trie图，就是加上fail指针
//2.用BFS来构造失败指针，与KMP算法相似的思想。
	void build()
	{
		queue<node*>q; 	//创建队列来进行广搜
		while(!q.empty())
			q.pop();
		q.push(root);	//让根节点入队
		while(!q.empty())
		{
			node *tmp=q.front();	//取队首元素
			node *temp=NULL;
			q.pop();	//出队
			for(int i=0;i<Max;i++)
			{
				if(tmp->next[i]==NULL)
					continue;
				if(tmp==root)	//第二层失配指针全部指向根结点
					tmp->next[i]->fail=root;
				else 	//创建fail指针
				{
					temp=tmp->fail;
					while(temp!=NULL)
					{
						if(temp->next[i]!=NULL)
						{
							tmp->next[i]->fail=temp->next[i];
							break;
						}
						temp=temp->fail;
					}
					if(temp==NULL)
						tmp->next[i]->fail=root;
				}
				q.push(tmp->next[i]);	//下一层全部入队
			}
		}
	}

	//在trie树中找在s文本中的单词个数
//	3.匹配过程分两种情况：
//	(1)当前字符匹配，表示从当前节点沿着树边有一条路径可以到达目标字符，此时只需沿该路径走向
//	 	下一个节点继续匹配即可，目标字符串指针移向下个字符继续匹配；
//	(2)当前字符不匹配，则去当前节点失败指针所指向的字符继续匹配，匹配过程随着指针指向root结束。
//	重复这2个过程中的任意一个，直到模式串走到结尾为止。
	int query(char *s)
	{
		int ans=0;	//单词个数初始化为0
		node *tmp=root;
		node *temp;
		for(int i=0;s[i];i++)
		{
			int id=s[i]-'a';
			while(tmp->next[id]==NULL && tmp!=root)
				tmp=tmp->fail;		//不是根节点，tmp指向rmp->fail继续查找
			tmp=tmp->next[id];
			if(tmp==NULL)
				tmp=root;
			temp=tmp;
			while(temp!=root && temp->ncount!=-1)
			{
				ans+=temp->ncount;	//找到满足的，将count加到ans中
				temp->ncount=-1;		//将count置为-1，防止重复计数
				temp=temp->fail;	//temp指向满足节点的失败指针所指向的节点继续查找
			}
		}
		return ans;
	}
};
char s[1000005];
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m;
        char keyWord[55];
        scanf("%d",&m);
        AC_Automata ac;
        while(m--)
        {
            scanf("%s",keyWord);
            ac.insertTrie(keyWord);
        }
        scanf("%s",s);
        ac.build();
        printf("%d\n",ac.query(s));
    }
}

//��ϰhttp://acm.hust.edu.cn/vjudge/contest/view.action?cid=17321#problem/C


const int Max=26;
class AC_Automata
{
	//������ݽṹ
	struct node
	{
		node *next[Max];
		node *fail;    	 //ʧ��ָ��
		int ncount;		 //�ַ�������
		//����
		node()
		{
			for(int i=0;i<Max;++i)
				next[i]=NULL;
			ncount=0;
			fail=NULL;
		}
	};

	node *root;		//�����
	//���캯��
	AC_Automata()
	{
		 root=new node();
	}

	//���뵥�ʵ�trie��
//1.����������Ҫ����һ��Trie���������Trie������ͨ��Trie�����Ǵ���һЩ��������ʡ�
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

	//����trieͼ�����Ǽ���failָ��
//2.��BFS������ʧ��ָ�룬��KMP�㷨���Ƶ�˼�롣
	void build()
	{
		queue<node*>q; 	//�������������й���
		while(!q.empty())
			q.pop();
		q.push(root);	//�ø��ڵ����
		while(!q.empty())
		{
			node *tmp=q.front();	//ȡ����Ԫ��
			node *temp=NULL;
			q.pop();	//����
			for(int i=0;i<Max;i++)
			{
				if(tmp->next[i]==NULL)
					continue;
				if(tmp==root)	//�ڶ���ʧ��ָ��ȫ��ָ������
					tmp->next[i]->fail=root;
				else 	//����failָ��
				{
					temp=tmp->fail;
					while(temp!=NULL)
					{
						if(temp->next[i]!=NULL)
						{
							tmp->next[i]->fail=temp->next[i];
							break;
						}
						temp=temp->fail;  //����Ѱ��ֱ�����ڵ��failָ����NULL
					}
					if(temp==NULL)
						tmp->next[i]->fail=root;
				}
				q.push(tmp->next[i]);	//��һ��ȫ�����
			}
		}
	}

	//��trie��������s�ı��еĵ��ʸ���
//	3.ƥ����̷����������
//	(1)��ǰ�ַ�ƥ�䣬��ʾ�ӵ�ǰ�ڵ�����������һ��·�����Ե���Ŀ���ַ�����ʱֻ���ظ�·������
//	 	��һ���ڵ����ƥ�伴�ɣ�Ŀ���ַ���ָ�������¸��ַ�����ƥ�䣻
//	(2)��ǰ�ַ���ƥ�䣬��ȥ��ǰ�ڵ�ʧ��ָ����ָ����ַ�����ƥ�䣬ƥ���������ָ��ָ��root������
//	�ظ���2�������е�����һ����ֱ��ģʽ���ߵ���βΪֹ��
	int query(char *s)
	{
		int ans=0;	//���ʸ�����ʼ��Ϊ0
		node *tmp=root;
		node *temp;
		for(int i=0;s[i];i++)
		{
			int id=s[i]-'a';
			while(tmp->next[id]==NULL && tmp!=root)
				tmp=tmp->fail;		//���Ǹ��ڵ㣬tmpָ��rmp->fail��������
			tmp=tmp->next[id];
			if(tmp==NULL)
				tmp=root;
			temp=tmp;
			while(temp!=root && temp->ncount!=-1)
			{
				ans+=temp->ncount;	//�ҵ�����ģ���ncount�ӵ�ans��
				temp->ncount=-1;		//��ncount��Ϊ-1����ֹ�ظ�����
				temp=temp->fail;	//tempָ������ڵ��ʧ��ָ����ָ��Ľڵ��������
			}
		}
		return ans;
	}
};





/**
在搜索法中，广度优先搜索法是寻找最短路经的首选。
1.广度优先搜索算法的基本步骤
1）建立一个队列，将初始结点入队，并设置队列头和尾指针
2）取出队列头（头指针所指）的结点进行扩展，从它扩展出子结点，并将这些结点按扩展的顺序加入队列。
3）如果扩展出的新结点与队列中的结点重复，则抛弃新结点，跳至第六步。
4）如果扩展出的新结点与队列中的结点不重复，则记录其父结点，并将它加入队列，更新队列尾指针。
5）如果扩展出的结点是目标结点，则输出路径，程序结束。否则继续下一步。
6）如果队列头的结点还可以扩展，直接返回第二步。否则将队列头指针指向下一结点，再返回第二步。
2.搜索路径的输出
搜索到目标结点后，需要输出搜索的路径。每个结点有一个数据域last，它记录了结点的父结点，
因此输出搜索路径时，就是从目标结点Q出发，根据last找到它的父结点，
再根据这个结点的last找到它的父结点，....,最后找到初始结点。
搜索的路径就是从初始结点循相反方向到达目标结点的路径。
*/
/**
 * 广度优先搜索
 * @param Vs 起点
 * @param Vd 终点
 */
bool BFS(Node& Vs, Node& Vd)
{
	queue<Node> Q;
	Node Vn, Vw;
	int i;

	//初始状态将起点放进队列Q
	Q.push(Vs);
	hash(Vw) = true;//设置节点已经访问过了！

	while (!Q.empty())//队列不为空，继续搜索！
	{
		//取出队列的头Vn
		Vn = Q.front();

		//从队列中移除
		Q.pop();

		while(Vw = Vn通过某规则能够到达的节点)
		{
			if (Vw == Vd){//找到终点了！
				//把路径记录，这里没给出解法
				return true;//返回
			}

			if (isValid(Vw) && !visit[Vw])
			{
				//Vw是一个合法的节点并且为白色节点
				Q.push(Vw);//加入队列Q
				hash(Vw) = true;//设置节点颜色
			}
		}
	}
	return false;//无解
}

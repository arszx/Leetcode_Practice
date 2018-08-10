//二叉树中和为某一值得路径。
void FindPath(BinaryTreeNode * pRoot, int expectedSum)
{
	if(pRoot==null)
		return;
	std::vector<int> path;
	int currentSum=0;
	FindPath(pRoot,expectedSum,path,currentSum);
}

void FindPath
(
	BinaryTreeNode * pRoot,
	int expectedSum,
	std::vector<int>& path,
	int & currentSum
)
{
	currentSum+=pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);
	
	//如果是叶节点，并且路径上结点的和等于输入的值
	//打印出这条路径
	bool idLeaf=pRoot->m_pLeft==NULL && pRoot->m_pRight==NULL;
	if(currentSum==expectedSum && isLeaf)
	{
		printf("A path is found:")
		std::vector<int>::iterator iter=path.begin();
		for(;iter!=path.end();++iter)
			printf("%d\t",*iter);
		
		printf("\n");
	}
	
	//如果不是叶节点，则遍历它的子节点
	if(pRoot->m_pLeft!=NULL)
		FindPath(pRoot->m_pLeft,expectedSum,path,currentSum);
	if(pRoot->m_pRight!=NULL)
		FindPath(pRoot->m_pRight,expectedSum,path,currentSum);
	
	//在返回到父节点之前，在路径上删除当前节点，
	//并在currentSum中减去当前节点的值
	currentSum -=pRoot->m_nValue;
	path.pop_back();
}

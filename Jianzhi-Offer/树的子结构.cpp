//输入两棵二叉树A和B，判断B是不是A的子结构。

//第一步判断寻找根节点
bool HasSubtree(BinaryTreeNode * pRoot1,BinaryTreeNode * pRoot2)
{
	bool result=false;
	
	if(pRoot1 !=NULL && pRoot2 !=NULL)
	{
		if(pRoot->m_nValue==pRoot2->m_nValue)
			result=DoesTreeHaveTree2(pRoot1,pRoot2);
		if(!result)
			result=HasSubtree(pRoot1->m_pLeft,pRoot2);
		if(!result)
			result=HasSubtree(pRoot1->m_pRight,pRoot2);
	}
	
	return result;
}

//第二步判断树A中以R为根节点的子树是不是和树B具有相同的结构
bool DoesTree1HaveTree2(BinaryTreeNode * pRoot1,BinaryTreeNode * pRoot2)
{
	if(pRoot2==NULL)
		return true;
	
	if(pRoot1==NULL)
		return false;
	
	if(pRoot1->m_nValue !=pRoot2->m_nValue)
		return false;
	
	return DoesTree1HaveTree2(pRoot1->m_pLeft,pRoot2->m_pLeft) &&
	DoesTree1HaveTree2(pRoot1->m_pRight,pRoot2->m_pRight);
}

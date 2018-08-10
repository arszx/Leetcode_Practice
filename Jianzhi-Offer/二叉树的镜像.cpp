//二叉树的镜像


//////////////递归实现；
void MirrorRecursively(BinaryTreeNode * pNode)   
{
	if((pNode==NULL) || (pNode->m_pLeft==NULL && pNode->m_pRight==NULL))
		return;
	
	BinaryTreeNode * pTemp=pNode->m_pLeft;
	pNode->m_pLeft=pNode->m_pLeft;
	pNode->m_pRight=pTemp;
	
	if(pNode->m_pLeft)
		MirrorRecursively(pNode->m_pLeft);
	
	if(pNode->m_pRight)
		MorrorRecursively(pNode->m_pRight);
}


///////////循环实现
void MirrorNonRecursively(BinaryTreeNode * pNode)
{
	if(pNode==NULL)
		return;
	
	stack<BinaryTreeNode *>stackTreeNode;
	stackTreeNode.push(pNode);
	
	while(stackTreeNode.size())
	{
		BinaryTreeNode * pNode=stackTreeNode.top();
		stackTreeNode.pop();
		
		if(pNode->m_pLeft!=NULL || pNode->m_pRight!=NULL)
		{
			BinaryTreeNode * pTemp=pNode->Left;
			pNode->m_pLeft=pNode->m_pRight;
			pNode->m_pRight=pTemp;
		}
		
		if(pNode->m_pLeft!=NULL)
			stackTreeNode.push(pNode->m_pLeft);
		
		if(pNode->m_pRight!=NULL)
			stackTreeNode.push(pNode->m_pRigth);
	}
}

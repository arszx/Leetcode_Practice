//二叉搜索树与双向链表
BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
	BinaryTreeNode* pLastNodeInList=NULL;
	ConvertNode(pRootOfTree,&pLastNodeInList);
	
	//pLastNodeInList指向双向链表的尾节点，
	//我们需要返回头结点
	BinaryTreeNode* pHeadOfList=pLastNodeInList;
	while(pHeadOfList!=NULL && pHeadOfList->m_pLeft!=NULL)
		pHeadOfList=pHeadOfList->m_pLeft;
	
	return pHeadOfList;
}

void ConvertNode(BinaryTreeNode* pNode,BinaryTreeNode** pLastNodeInList)
{
	if(pNode==NULL)
		return;
	
	BinaryTreeNode* pCurrent=pNode;
	
	if(pCurrent->m_pLeft!=NULL)
		ConvertNode(pCurrent->m_pLeft,pLastNodeInList);
	
	pCurrent->m_pLeft=*pLastNodeINList;
	if(*pLastNodeInList!=NULL)
		(*pLastNodeInList)->m_pRight=pCurrent;
	
	*pLastNodeInList=pCurrent;
	
	if(pCurrent->m_pRight!=NULL)
		ConvertNode(pCurrent->m_pRight,pLastNodeInList);
}

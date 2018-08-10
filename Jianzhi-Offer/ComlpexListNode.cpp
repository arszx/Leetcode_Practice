//复杂链表的复制

//第一步，把N'链接在N的后面
void CloneNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode=pHead;
	while(pNode!=NULL)
	{
		ComplexListNode* pCloned=new ComplexListNode();
		pCloned->m_nValue=pNode->m_nValue;
		pCloned->m_pNext=pNode->m_pNext;
		pCloned->m_pSibling=NULL;
		
		pNode->m_pNext=pCloned;
		
		pNode=pCloned->m_pNext;
	}
}

//N->N',S->S'
void ConnectSiblingNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode=pHead;
	while(pNode!=NULL)
	{
		ComplexListNode* pCloned=pNode->m_pNext;
		if(pNode->m_pSibling!=NULL)
		{
			pCloned->m_pSibling=pNode->m_pSibling->m_pNext;
		}
		pNode=pCloned->m_pNext;
	}
}

//拆分两个链表
ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode=pHead;
	ComplexListNode* pClonedHead=NULL;
	ComplexListNode* pClonedNode=NULL;
	
	if(pNode!=NULL)
	{
		pClonedHead=pClonedNode=pNode->m_pNext;
		pNode->m_pNext=pClonedNode->m_pNext;
		pNode=pNode->m_pNext;
	}
	
	while(pNode!=NULL)
	{
		pClonedNode->m_pNext=pNode->m_pNext;
		pClonedNode=pClonedNode->m_pNext;
		pNode->m_pNext=pClonedNode->m_pNext;
		pNode=pNode->m_pNext;
	}
	return pClonedHead;
}

//合起来
ComplexListNode* Clon(ComplexListNode* pHead)
{
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}

//////删除节点////////////////
void DeleteNode(ListNode ** pListHead,ListNode * pToBeDelete)
{
	if(!pListHead || !pToBeDelete)
		return;
	
	//要删除的节点不是尾节点
	if(pToBeDelete->m_pNext!=NULL)
	{
		ListNode *pNext=pToBeDelete->m_pNext;
		pToBeDelete->m_nValue=pNext->m_nValue;
		pToBeDelete->m_pNext=pNext->m_pNext;
		
		delete pNext;
		pNext=NULL;
	}
	//链表只有一个节点，删除头节点（也是尾节点）
	else if(*pListHead==pToBeDelete)
	{
		delete pToBeDelete;
		pToBeDelete=NULL;
		*pListHead=NULL;
	}
	//链表中有多个节点，删除尾节点
	else
	{
		ListNode *pNode=*pListHead;
		while(pNode->m_pNext!=pToBeDelete)
			pNode=pNode->m_pNext;
		
		pNode->m_pNext=NULL;
		delete pToBeDelete;
		pToBeDelete=NULL;
	}
}

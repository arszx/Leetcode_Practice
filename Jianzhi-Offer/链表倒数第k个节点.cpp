//本题考察链表的鲁棒性，要考虑的包括：
//1空链表；2k大于链表节点数；3输入的k为0
ListNode * FindKthToTail(ListNode * pListHead,unsigned int k)
{
  if(pListHead==NULL || k==0)
    return NULL;
  
  ListNode * pAhead=pListHead;
  ListNode * pBehind=NULL;
  
  for(unsigned int i=0;i<k-1;++i)
  {
    if(pAhead->m_pNext !=NULL)
      pAhead=pAhead->m_pNext;
    else
      return NULL;
  }
  
  pBehind=pListHead;
  while(pAhead->m_pNext!=NULL)
  {
    pAhead=pAhead->m_pNext;
    pBehind=pBehind->m_pNext;
  }
  
  return pBehind;
}
